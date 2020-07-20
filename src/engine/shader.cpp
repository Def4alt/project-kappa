#include "shader.h"
#include "error.h"
#include "logger.h"
#include <GL/glew.h>
#include <sstream>

struct engine::Shader::ShadersSource {
    std::string vertex_shader;
    std::string fragment_shader;
};

engine::Shader::Shader(const std::string &filepath)
    :renderer_id_(0), filepath_(filepath) {
    const auto shaders_source = from_glsl_file(filepath);
    renderer_id_ = create_shader(shaders_source.vertex_shader, shaders_source.fragment_shader);
}

engine::Shader::~Shader() {
    glDeleteProgram(renderer_id_);
}

unsigned engine::Shader::create_shader(const std::string &vertex_shader, const std::string &fragment_shader) const {
    const auto vs = compile_shader(GL_VERTEX_SHADER, vertex_shader);
    const auto fs = compile_shader(GL_FRAGMENT_SHADER, fragment_shader);

    const auto program = glCreateProgram();

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

engine::Shader::ShadersSource engine::Shader::from_glsl_file(const std::string &filepath) const {
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

unsigned engine::Shader::compile_shader(unsigned int type, const std::string &source) const {
    const auto id = glCreateShader(type);
    const auto* src = source.c_str();

    glShaderSource(id, 1, &src, nullptr);

    glCompileShader(id);

    int result;

    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        auto* const message = (char*)malloc(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        SPDLOG_ERROR(message);
    }

    return id;
}

void engine::Shader::bind() const {
    glUseProgram(renderer_id_);
}

void engine::Shader::unbind() const {
    glUseProgram(0);
}

void engine::Shader::set_uniform_4f(const std::string &name, float v0, float v1, float v2, float v3) {
    glUniform4f(get_uniform_location(name), v0, v1, v2, v3);
}

void engine::Shader::set_uniform_1i(const std::string &name, int v0) {
    glUniform1i(get_uniform_location(name), v0);
}

void engine::Shader::set_uniform_mat4f(const std::string &name, const glm::mat4 &v0) {
    glUniformMatrix4fv(get_uniform_location(name), 1, GL_FALSE, &v0[0][0]);
}

int engine::Shader::get_uniform_location(const std::string &name) {
    if (uniform_location_cache_.find(name) != uniform_location_cache_.end())
        return uniform_location_cache_[name];

    const auto location = glGetUniformLocation(renderer_id_, name.c_str());
    if (location == -1)
        SPDLOG_WARN("uniform '{0}' doesn't exist", name);

    uniform_location_cache_[name] = location;

    return location;
}
