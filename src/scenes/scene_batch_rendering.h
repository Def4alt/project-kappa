#ifndef PROJECT_KAPPA_SCENE_BATCH_RENDERING_H
#define PROJECT_KAPPA_SCENE_BATCH_RENDERING_H

#include "scene.h"

namespace scene {

    class SceneBatchRendering: public Scene {
    public:
        SceneBatchRendering();

        void render() override;
        void imgui_render() override;

    private:
        std::unique_ptr<VertexArray> vao_;
        std::unique_ptr<IndexBuffer> index_buffer_;
        std::unique_ptr<Shader> shader_;
        std::unique_ptr<Texture> texture_;
        std::unique_ptr<VertexBuffer> vertex_buffer_;

        glm::vec3 translation_;
        glm::mat4 proj_, view_;
    };
}



#endif //PROJECT_KAPPA_SCENE_BATCH_RENDERING_H
