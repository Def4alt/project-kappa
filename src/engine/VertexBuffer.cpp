#include "VertexBuffer.hpp"
#include "Vertex.hpp"

namespace engine
{
    VertexBuffer::VertexBuffer(uint32_t capacity, const void *data, const uint32_t type)
        : renderer_id_(0)
    {
        glGenBuffers(1, &renderer_id_);
        glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
        glBufferData(GL_ARRAY_BUFFER, capacity * sizeof(Vertex), data, type);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &renderer_id_);
    }

    void VertexBuffer::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
    }

    void VertexBuffer::unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
} // namespace engine
