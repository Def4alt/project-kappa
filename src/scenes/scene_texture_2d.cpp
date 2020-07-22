#include "renderer.h"
#include <imgui/imgui.h>
#include "scene_texture_2d.h"

#include "glm/gtc/matrix_transform.hpp"
#include "index_buffer.h"
#include "shader.h"
#include "texture.h"
#include "vertex.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

scene::SceneTexture2D::SceneTexture2D() {
    std::array<engine::Vertex, 4> vertices;

    engine::Vertex* buffer = vertices.data();

    glm::vec3 pos(-50.0f, -50.0f, 0.0f);
    glm::vec4 color(0.4f, 0.5f, 0.5f, 1.0f);

    buffer = engine::Vertex::create_quad(buffer, pos, color, 0, glm::vec2(100.0f, 100.0f));

    vao_ = std::make_unique<engine::VertexArray>();
    vertex_buffer_ = std::make_unique<engine::VertexBuffer>(4, vertices.data(), GL_STATIC_DRAW);

    engine::VertexBufferLayout layout;
    layout.push<float>(3);
    layout.push<float>(4);
    layout.push<float>(2);
    layout.push<float>(1);

    vao_->add_buffer(*vertex_buffer_, layout);

    index_buffer_ = std::make_unique<engine::IndexBuffer>(6);
    index_buffer_->set_count(6);

    shader_ = std::make_unique<engine::Shader>("assets/shaders/basic.shader");
    shader_->bind();

    shader_->set_uniform_4f("u_color", 0.3f, 0.4f, 0.5f, 1.0f);

    texture_ = std::make_unique<engine::Texture>("assets/textures/sprite.png");

    shader_->set_uniform_1i("u_texture", 0);

    proj_ = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f);
    view_ = translate(glm::mat4(1.0), glm::vec3(0, 0, 0));

    translation_a_ = glm::vec3(200, 200, 0);
    translation_b_ = glm::vec3(400, 400, 0);
}

void scene::SceneTexture2D::render() {
    engine::Renderer::clear();
    texture_->bind();

    {
        const auto model = translate(glm::mat4(1.0), translation_a_);
        const auto mvp = proj_ * view_ * model;
        shader_->bind();
        shader_->set_uniform_mat4f("u_MVP", mvp);

        engine::Renderer::draw(*vao_, *index_buffer_);
    }

    {
        const auto model = translate(glm::mat4(1.0), translation_b_);
        const auto mvp = proj_ * view_ * model;
        shader_->bind();
        shader_->set_uniform_mat4f("u_MVP", mvp);

        engine::Renderer::draw(*vao_, *index_buffer_);
    }
}

void scene::SceneTexture2D::imgui_render() {
    ImGui::SliderFloat3("TranslationA", &translation_a_.x, 0.0f, 800.0f);
    ImGui::SliderFloat3("TranslationB", &translation_b_.x, 0.0f, 800.0f);
}
