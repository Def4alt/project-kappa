#ifndef KAPPA_ENGINE_VERTEX_BUFFER_HPP
#define KAPPA_ENGINE_VERTEX_BUFFER_HPP

#include <GL/glew.h>
#include <stdint.h>

namespace engine
{
    class VertexBuffer
    {
    public:
        VertexBuffer(uint32_t capacity, const void *data = nullptr, const uint32_t type = GL_DYNAMIC_DRAW);
        ~VertexBuffer();

        void bind() const;
        void unbind() const;

    protected:
        uint32_t renderer_id_;
    };
} // namespace engine

#endif // KAPPA_ENGINE_VERTEX_BUFFER_HPP