#include "shader.h"
#include "error.h"
#include "logger.h"
#include <GL/glew.h>
#include <sstream>

struct Shader::ShadersSource {
    std::string vertex_shader;
    std::string fragment_shader;
};

Shader::Shader(const std::string &filepath)
    :renderer_id_(0), filepath_(filepath) {
    const auto shaders_source = from_glsl_file(filepath);
    renderer_id_ = create_shader(shaders_source.vertex_shader, shaders_source.fragment_shader);
}

Shader::~Shader() {
    GL_WRAP(glDeleteProgram(renderer_id_))
}

unsigned Shader::create_shader(const std::string &vertex_shader, const std::string &fragment_shader) const {
    const auto vs = compile_shader(GL_VERTEX_SHADER, vertex_shader);
    const auto fs = compile_shader(GL_FRAGMENT_SHADER, fragment_shader);

    GL_WRAP(const auto program = glCreateProgram())

    GL_WRAP(glAttachShader(program, vs))
    GL_WRAP(glAttachShader(program, fs))

    GL_WRAP(glLinkProgram(program))
    GL_WRAP(glDeleteShader(vs))
    GL_WRAP(glDeleteShader(fs))

    return program;
}

Shader::ShadersSource Shader::from_glsl_file(const std::string &filepath) const {
    std::ifstream stream(filepath);

    std::string line;
    std::stringstream ss[2];

    unsigned int mode = 0;

    while (getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos)
                mode = GL_VERTEX_SHADER;
            else if (line.find("fragment") != std::string::npos)
                mode = GL_FRAGMENT_SHADER;
        }
        else if (mode == GL_VERTEX_SHADER)
            ss[0] << line << '\n';
        else if (mode == GL_FRAGMENT_SHADER)
            ss[1] << line << '\n';
    }

    stream.close();

    ShadersSource source;

    source.vertex_shader = ss[0].str();
    source.fragment_shader = ss[1].str();

    return source;
}

unsigned Shader::compile_shader(unsigned int type, const std::string &source) const {
    const auto id = glCreateShader(type);
    const auto* src = source.c_str();

    GL_WRAP(glShaderSource(id, 1, &src, nullptr))

    GL_WRAP(glCompileShader(id))

    int result;

    GL_WRAP(glGetShaderiv(id, GL_COMPILE_STATUS, &result))

    if (result == GL_FALSE)
    {
        int length;
        GL_WRAP(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length))
        auto* const message = (char*)malloc(length * sizeof(char));
        GL_WRAP(glGetShaderInfoLog(id, length, &length, message))

        logger::log(ERROR, message);
    }

    return id;
}

void Shader::bind() const {
    GL_WRAP(glUseProgram(renderer_id_))
}

void Shader::unbind() const {
    GL_WRAP(glUseProgram(0))
}

void Shader::set_uniform_4f(const std::string &name, float v0, float v1, float v2, float v3) {
    GL_WRAP(glUniform4f(get_uniform_location(name), v0, v1, v2, v3))
}

void Shader::set_uniform_1i(const std::string &name, int v0) {
    GL_WRAP(glUniform1i(get_uniform_location(name), v0))
}

void Shader::set_uniform_mat4f(const std::string &name, const glm::mat4 &v0) {
    GL_WRAP(glUniformMatrix4fv(get_uniform_location(name), 1, GL_FALSE, &v0[0][0]))
}

int Shader::get_uniform_location(const std::string &name) {
    if (uniform_location_cache_.find(name) != uniform_location_cache_.end())
        return uniform_location_cache_[name];

    GL_WRAP(const auto location = glGetUniformLocation(renderer_id_, name.c_str()))
    if (location == -1)
        logger::log(WARNING, "uniform '" + name + "' doesn't exist");

    uniform_location_cache_[name] = location;

    return location;
}
