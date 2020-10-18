#include "ColorScene.hpp"
#include <gl/glew.h>
#include <imgui/imgui.h>
#include "Renderer.hpp"

namespace scene
{
    ColorScene::ColorScene()
        : color_{0.2f, 0.3f, 0.4f, 1.0f}
    {
    }

    void ColorScene::render()
    {
        engine::Renderer::clear_color(color_);
    }

    void ColorScene::imgui_render()
    {
        ImGui::ColorEdit4("Clear color", &color_.r);
    }
} // namespace scene
