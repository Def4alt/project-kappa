#include <memory>
#include "vertex_array.h"
#include "shader.h"
#include "texture.h"
#include "index_buffer.h"
#include "renderer.h"
#include <imgui/imgui.h>
#include "scene_batch_rendering.h"
#include "logger.h"
#include "debug.h"
#include "vertex.h"
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"
#include <glm/gtc/matrix_transform.hpp>

scene::SceneBatchRendering::SceneBatchRendering() {
    engine::Debug::enable_gl_debugging();

    shader_ = std::make_unique<engine::Shader>("assets/shaders/basic.shader");
    shader_->bind();

    texture_ = std::make_unique<engine::Texture>("assets/textures/sprite.png");

    int samplers[32];
    for (int i = 0; i < 32; i++)
        samplers[i] = i;

    camera_controller_ = std::make_unique<engine::CameraController>(4.0f / 3.0f);

    shader_->set_uniform_1iv("u_textures", 32, samplers);

    translation_ = glm::vec3(-camera_controller_->get_aspect_ratio() + 1.0f, 0, 0);

    texture_->unbind();

    engine::BatchRenderer::init();
}

scene::SceneBatchRendering::~SceneBatchRendering() {
    engine::BatchRenderer::shutdown();
}

void scene::SceneBatchRendering::render() {
    engine::Renderer::clear();
    engine::BatchRenderer::reset_stats();

    const auto model = glm::translate(glm::mat4(1.0), translation_);
    const auto mvp = camera_controller_->get_camera().get_view_projection_matrix() * model;
    shader_->bind();
    shader_->set_uniform_mat4f("u_MVP", mvp);

    engine::BatchRenderer::begin_batch();

    for (float x = -1.0f; x < quad_count_ * 100; x += 100)
    {
        for (float y = -1.0f; y < quad_count_ * 100; y += 100)
        {
            glm::vec3 pos(x, y, 0.0f);
            glm::vec4 color(0.3f, 0.4f, 0.5f, 1.0f);
            engine::BatchRenderer::draw_quad(pos, glm::vec2(100.0f, 100.0f), color);
        }
    }

    engine::BatchRenderer::end_batch();

    engine::BatchRenderer::flush();
}

void scene::SceneBatchRendering::imgui_render() {
    ImGui::SliderFloat3("Translation", &translation_.x, 0.0f, 8000.0f);
    ImGui::SliderInt("Quad Count", &quad_count_, 1, 1000);
    ImGui::LabelText("Draw calls: ", "%d", engine::BatchRenderer::get_stats().draw_count);
    ImGui::LabelText("Quads: ", "%d", engine::BatchRenderer::get_stats().quad_count);
}

void scene::SceneBatchRendering::update(float delta_time) {
    camera_controller_->update(delta_time);
}