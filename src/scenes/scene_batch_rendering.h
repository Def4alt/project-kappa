#ifndef PROJECT_KAPPA_SCENE_BATCH_RENDERING_H
#define PROJECT_KAPPA_SCENE_BATCH_RENDERING_H

#include "scene.h"
#include "index_buffer.h"
#include "shader.h"
#include "texture.h"
#include "vertex_array.h"
#include "vertex_buffer.h"

namespace scene {

    class SceneBatchRendering: public Scene {
    public:
        SceneBatchRendering();

        void render() override;
        void imgui_render() override;

    private:
        std::unique_ptr<engine::VertexArray> vao_;
        std::unique_ptr<engine::IndexBuffer> index_buffer_;
        std::unique_ptr<engine::Shader> shader_;
        std::unique_ptr<engine::Texture> texture_;
        std::unique_ptr<engine::VertexBuffer>  vertex_buffer_;

        glm::vec3 translation_;
        glm::mat4 proj_, view_;
    };
}



#endif //PROJECT_KAPPA_SCENE_BATCH_RENDERING_H
