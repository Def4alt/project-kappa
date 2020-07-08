#include <renderer.h>
#include <imgui/imgui.h>
#include "scene_texture_2d.h"

#include "glm/gtc/matrix_transform.hpp"

scene::SceneTexture2D::SceneTexture2D() {
    float positions[] = {
            -50.0f, -50.0f, 0.0f, 0.0f,
            50.0f, -50.0f, 1.0f, 0.0f,
            50.0f, 50.0f, 1.0f, 1.0f,
            -50.0f, 50.0f, 0.0f, 1.0f
    };

    unsigned indices[] = {
            0, 1, 2,
            2, 3, 0
    };

    vao_ = std::make_unique<VertexArray>();
    vertex_buffer_ = std::make_unique<VertexBuffer>(positions, 4 * 4 * sizeof(float));

    VertexBufferLayout layout;
    layout.push<float>(2);
    layout.push<float>(2);

    vao_->add_buffer(*vertex_buffer_, layout);

    index_buffer_ = std::make_unique<IndexBuffer>(indices, 6);

    shader_ = std::make_unique<Shader>("assets/shaders/basic.shader");
    shader_->bind();

    shader_->set_uniform_4f("u_color", 0.3f, 0.4f, 0.5f, 1.0f);

    texture_ = std::make_unique<Texture>("assets/textures/sprite.png");

    shader_->set_uniform_1i("u_texture", 0);

    proj_ = glm::ortho(0.0f, 1920.0f, 0.0f, 1080.0f, -1.0f, 1.0f);
    view_ = translate(glm::mat4(1.0), glm::vec3(0, 0, 0));

    translation_a_ = glm::vec3(200, 200, 0);
    translation_b_ = glm::vec3(400, 400, 0);
}

void scene::SceneTexture2D::render() {
    GL_WRAP(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
    const Renderer renderer;

    renderer.clear();
    texture_->bind();

    {
        const auto model = translate(glm::mat4(1.0), translation_a_);
        const auto mvp = proj_ * view_ * model;
        shader_->bind();
        shader_->set_uniform_mat4f("u_MVP", mvp);

        renderer.draw(*vao_, *index_buffer_, *shader_);
    }

    {
        const auto model = translate(glm::mat4(1.0), translation_b_);
        const auto mvp = proj_ * view_ * model;
        shader_->bind();
        shader_->set_uniform_mat4f("u_MVP", mvp);

        renderer.draw(*vao_, *index_buffer_, *shader_);
    }
}

void scene::SceneTexture2D::imgui_render() {
    ImGui::SliderFloat3("TranslationA", &translation_a_.x, 0.0f, 800.0f);
    ImGui::SliderFloat3("TranslationB", &translation_b_.x, 0.0f, 800.0f);
}