#include "Renderer.hpp"

#include <gl/glew.h>

namespace engine
{
    void Renderer::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    void Renderer::clear_color(glm::vec4 &color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void Renderer::draw(const VertexArray &vao, const IndexBuffer &ib)
    {
        vao.bind();
        ib.bind();

        glDrawElements(GL_TRIANGLES, ib.get_count(), GL_UNSIGNED_INT, nullptr);
    }
} // namespace engine
