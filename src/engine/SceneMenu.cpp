#include "SceneMenu.hpp"

#include <imgui/imgui.h>

void engine::SceneMenu::imgui_render()
{
    for (auto &test : tests_)
    {
        if (ImGui::Button(test.first.c_str()))
        {
            current_test_ = test.second();
        }
    }
}