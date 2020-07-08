#include "error.h"
#include "scene_clear_color.h"
#include <GL/glew.h>
#include <imgui/imgui.h>

scene::SceneClearColor::SceneClearColor()
    :color_{0.2f, 0.3f, 0.4f, 1.0f}{

}

void scene::SceneClearColor::render() {
    GL_WRAP(glClearColor(color_[0], color_[1], color_[2], color_[3]))
    GL_WRAP(glClear(GL_COLOR_BUFFER_BIT))
}

void scene::SceneClearColor::imgui_render() {
    ImGui::ColorEdit4("Clear color", color_);
}
