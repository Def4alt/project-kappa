#include "ColorScene.hpp"
#include <gl/glew.h>
#include <imgui/imgui.h>

namespace scene
{
    ColorScene::ColorScene()
        : color_{0.2f, 0.3f, 0.4f, 1.0f}
    {
    }

    void ColorScene::render()
    {
        glClearColor(color_[0], color_[1], color_[2], color_[3]);
    }

    void ColorScene::imgui_render()
    {
        ImGui::ColorEdit4("Clear color", color_);
    }
} // namespace scene
