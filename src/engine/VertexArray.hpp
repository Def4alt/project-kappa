#ifndef KAPPA_ENGINE_VERTEX_ARRAY_HPP
#define KAPPA_ENGINE_VERTEX_ARRAY_HPP

#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"

namespace engine
{
    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void add_buffer(const VertexBuffer &vb, const VertexBufferLayout &layout);
        void bind() const;
        void unbind() const;

    protected:
        uint32_t renderer_id_;
    };
} // namespace engine

#endif // KAPPA_ENGINE_VERTEX_ARRAY_HPP