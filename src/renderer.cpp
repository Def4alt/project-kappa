#include "renderer.h"

void Renderer::clear() const {
    GL_WRAP(glClear(GL_COLOR_BUFFER_BIT))
}

void Renderer::draw(const VertexArray &vao, const IndexBuffer &ib, const Shader &shader) const {
    shader.bind();
    vao.bind();
    ib.bind();

    GL_WRAP(glDrawElements(GL_TRIANGLES, ib.get_count(), GL_UNSIGNED_INT, nullptr))
}
