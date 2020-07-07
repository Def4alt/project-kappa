#include <imgui/imgui.h>
#include "scene_menu.h"

scene::SceneMenu::SceneMenu(scene::Scene *&current_test)
    : current_test_(current_test) {

}

void scene::SceneMenu::imgui_render() {
    for(auto& test : tests_)
    {
        if (ImGui::Button(test.first.c_str()))
            current_test_ = test.second();
    }
}
