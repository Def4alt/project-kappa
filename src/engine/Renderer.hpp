#ifndef KAPPA_ENGINE_RENDERER_HPP
#define KAPPA_ENGINE_RENDERER_HPP

#include <glm/glm.hpp>
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"

namespace engine
{
    class Renderer
    {
    public:
        static void clear();
        static void clear_color(glm::vec4 &color);
        static void draw(const VertexArray &vao, const IndexBuffer &ib);
    };
} // namespace engine

#endif // KAPPA_ENGINE_RENDERER_HPP