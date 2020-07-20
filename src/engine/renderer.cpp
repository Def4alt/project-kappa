#include "renderer.h"
#include "index_buffer.h"
#include "shader.h"
#include "vertex_array.h"

void engine::Renderer::clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void engine::Renderer::draw(const VertexArray &vao, const engine::IndexBuffer &ib, const Shader &shader) const {
    shader.bind();
    vao.bind();
    ib.bind();

    glDrawElements(GL_TRIANGLES, ib.get_count(), GL_UNSIGNED_INT, nullptr);
}
