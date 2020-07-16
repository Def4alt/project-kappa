#include <memory>
#include "vertex_array.h"
#include "shader.h"
#include "texture.h"
#include "index_buffer.h"
#include <glm/gtc/matrix_transform.hpp>
#include "renderer.h"
#include <imgui/imgui.h>
#include "scene_batch_rendering.h"

scene::SceneBatchRendering::SceneBatchRendering() {

    float positions[] = {
            -50.0f, -50.0f, 0.0f, 0.0f,
            50.0f, -50.0f, 1.0f, 0.0f,
            50.0f, 50.0f, 1.0f, 1.0f,
            -50.0f, 50.0f, 0.0f, 1.0f,

            100.0f, 100.0f, 0.0f, 0.0f,
            200.0f, 100.0f, 1.0f, 0.0f,
            200.0f, 200.0f, 1.0f, 1.0f,
            100.0f, 200.0f, 0.0f, 1.0f
    };

    unsigned indices[] = {
            0, 1, 2,
            2, 3, 0,

            4, 5, 6,
            6, 7, 4
    };

    vao_ = std::make_unique<VertexArray>();
    vertex_buffer_ = std::make_unique<VertexBuffer>(positions, 2 * 4 * 4 * sizeof(float));

    VertexBufferLayout layout;
    layout.push<float>(2);
    layout.push<float>(2);
    layout.push<float>(4);

    vao_->add_buffer(*vertex_buffer_, layout);

    index_buffer_ = std::make_unique<IndexBuffer>(indices, 12);

    shader_ = std::make_unique<Shader>("assets/shaders/basic.shader");
    shader_->bind();

    shader_->set_uniform_4f("u_color", 0.3f, 0.4f, 0.5f, 1.0f);

    texture_ = std::make_unique<Texture>("assets/textures/sprite.png");

    shader_->set_uniform_1i("u_texture", 0);

    proj_ = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f);
    view_ = translate(glm::mat4(1.0), glm::vec3(0, 0, 0));

    translation_ = glm::vec3(200, 200, 0);
}

void scene::SceneBatchRendering::render() {

    GL_WRAP(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
    const Renderer renderer;

    renderer.clear();
    texture_->bind();

    {
        const auto model = translate(glm::mat4(1.0), translation_);
        const auto mvp = proj_ * view_ * model;
        shader_->bind();
        shader_->set_uniform_mat4f("u_MVP", mvp);

        renderer.draw(*vao_, *index_buffer_, *shader_);
    }
}

void scene::SceneBatchRendering::imgui_render() {
    ImGui::SliderFloat3("Translation", &translation_.x, 0.0f, 800.0f);
}
