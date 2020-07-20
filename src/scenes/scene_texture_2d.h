#ifndef PROJECT_KAPPA_SCENE_TEXTURE_2D_H
#define PROJECT_KAPPA_SCENE_TEXTURE_2D_H

#include "vertex_array.h"
#include <memory>
#include "index_buffer.h"
#include "shader.h"
#include "texture.h"
#include <glm/glm.hpp>
#include "scene.h"
#include "vertex_buffer.h"

namespace scene {
    class SceneTexture2D: public Scene  {
    public:
        SceneTexture2D();

        void render() override;
        void imgui_render() override;

    private:
        std::unique_ptr<engine::VertexArray> vao_;
        std::unique_ptr<engine::IndexBuffer> index_buffer_;
        std::unique_ptr<engine::Shader> shader_;
        std::unique_ptr<engine::Texture> texture_;
        std::unique_ptr<engine::VertexBuffer> vertex_buffer_;

        glm::vec3 translation_a_, translation_b_;
        glm::mat4 proj_, view_;
    };
}


#endif //PROJECT_KAPPA_SCENE_TEXTURE_2D_H
