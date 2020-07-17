#include "renderer.h"

void Renderer::clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Renderer::draw(const VertexArray &vao, const IndexBuffer &ib, const Shader &shader) const {
    shader.bind();
    vao.bind();
    ib.bind();

    glDrawElements(GL_TRIANGLES, ib.get_count(), GL_UNSIGNED_INT, nullptr);
}
