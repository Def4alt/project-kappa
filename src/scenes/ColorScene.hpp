#ifndef PROJECT_KAPPA_COLOR_SCENE_HPP
#define PROJECT_KAPPA_COLOR_SCENE_HPP

#include "Scene.hpp"
#include "Renderer.hpp"

namespace scene
{
    class ColorScene : public engine::Scene
    {
    public:
        ColorScene();

        void render() override;
        void imgui_render() override;

    protected:
        glm::vec4 color_;
    };

} // namespace scene

#endif // PROJECT_KAPPA_COLOR_SCENE_HPP