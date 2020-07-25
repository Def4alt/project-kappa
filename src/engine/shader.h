#ifndef PROJECT_KAPPA_ENGINE_SHADER_H
#define PROJECT_KAPPA_ENGINE_SHADER_H

#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

namespace engine {
    class Shader {
    public:
        struct ShadersSource;

        Shader(const std::string& filepath);
        ~Shader();

        void bind() const;
        void unbind() const;

        void set_uniform_4f(const std::string& name, float v0, float v1, float v2, float v3);
        void set_uniform_1i(const std::string& name, int v0);
        void set_uniform_mat4f(const std::string& name, const glm::mat4& v0);
        void set_uniform_1iv(const std::string& name, uint32_t count, int *value);

    private:
        uint32_t renderer_id_;
        std::string filepath_;
        std::unordered_map<std::string, int> uniform_location_cache_;

        int get_uniform_location(const std::string& name);
        uint32_t create_shader(const std::string& vertex_shader, const std::string& fragment_shader) const;
        ShadersSource from_glsl_file(const std::string& filepath) const;
        uint32_t compile_shader(uint32_t type, const std::string& source) const;
    };
}


#endif //PROJECT_KAPPA_ENGINE_SHADER_H
