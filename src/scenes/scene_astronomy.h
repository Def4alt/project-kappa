#ifndef PROJECT_KAPPA_SCENE_ASTRONOMY_H
#define PROJECT_KAPPA_SCENE_ASTRONOMY_H

#include "scene.h"
#include "index_buffer.h"
#include "shader.h"
#include "texture.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "batch_renderer.h"
#include "camera_controller.h"
#include <memory>

namespace scene {
	class SceneAstronomy: public Scene {
    public:
     	SceneAstronomy();
    	~SceneAstronomy();

        void render() override;
        void imgui_render() override;
        void update(float delta_time) override;

        
    private:
        std::unique_ptr<engine::Shader> shader_;
        std::unique_ptr<engine::Texture> texture_;
        std::unique_ptr<engine::CameraController> camera_controller_;

        int quad_count_ = 10;
        glm::vec2 size_;
        glm::vec3 translation_;
        glm::mat4 proj_, view_;
	};
}

#endif // PROJECT_KAPPA_SCENE_ASTRONOMY_H
