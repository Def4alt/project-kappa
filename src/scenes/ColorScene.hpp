#ifndef PROJECT_KAPPA_COLOR_SCENE_HPP
#define PROJECT_KAPPA_COLOR_SCENE_HPP

#include "Scene.hpp"

namespace scene
{
    class ColorScene : public engine::Scene
    {
    public:
        ColorScene();

        void render() override;
        void imgui_render() override;

    protected:
        float color_[4];
    };

} // namespace scene

#endif // PROJECT_KAPPA_COLOR_SCENE_HPP