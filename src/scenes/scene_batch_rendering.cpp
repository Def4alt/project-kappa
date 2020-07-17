#include <memory>
#include "vertex_array.h"
#include "shader.h"
#include "texture.h"
#include "index_buffer.h"
#include <glm/gtc/matrix_transform.hpp>
#include "renderer.h"
#include <imgui/imgui.h>
#include "scene_batch_rendering.h"
#include "logger.h"
#include "error.h"

scene::SceneBatchRendering::SceneBatchRendering() {
    error::enable_gl_debugging();

    const unsigned max_quads = 50000;
    const unsigned max_vertices = max_quads * 4;
    const unsigned max_indices = max_quads * 6;

    vao_ = std::make_unique<VertexArray>();

    vertex_buffer_ = std::make_unique<VertexBuffer>(max_vertices);

    VertexBufferLayout layout;

    layout.push<float>(3);
    layout.push<float>(4);
    layout.push<float>(2);
    layout.push<float>(1);

    vao_->add_buffer(*vertex_buffer_, layout);

    index_buffer_ = std::make_unique<IndexBuffer>(max_indices);

    shader_ = std::make_unique<Shader>("assets/shaders/basic.shader");
    shader_->bind();

    texture_ = std::make_unique<Texture>("assets/textures/sprite.png");

    shader_->set_uniform_1i("u_texture", 0);

    proj_ = glm::ortho(0.0f, 16000.0f, 0.0f, 12000.0f, -1.0f, 1.0f);
    view_ = translate(glm::mat4(1.0), glm::vec3(0, 0, 0));

    translation_ = glm::vec3(0, 0, 0);

    texture_->unbind();
    shader_->unbind();
    index_buffer_->unbind();
    vertex_buffer_->unbind();
    vao_->unbind();
}

void scene::SceneBatchRendering::render() {
    std::array<Vertex, 50000> vertices;
    Vertex* buffer = vertices.data();

    glm::vec4 color(0.3f, 0.4f, 0.5f, 1.0f);

    unsigned indices_count = 0;
    for (int x = 0; x < 11100; x += 100)
    {
        for (int y = 0; y < 11100; y += 100)
        {
            glm::vec3 pos(x, y, 0.0f);
            buffer = Vertex::create_quad(buffer, pos, color, 0, 100.0f);
            indices_count += 6;
        }
    }
    index_buffer_->set_count(indices_count);

    vertex_buffer_->bind();
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data());

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
    ImGui::SliderFloat3("Translation", &translation_.x, 0.0f, 8000.0f);
}
