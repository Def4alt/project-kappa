#include "IndexBuffer.hpp"
#include <GL/glew.h>
#include <vector>

namespace engine
{
    IndexBuffer::IndexBuffer(const uint32_t capacity)
        : count_(0), renderer_id_(0)
    {
        static_assert(sizeof(uint32_t) == sizeof(GLuint));

        std::vector<uint32_t> indices(capacity);
        uint32_t offset = 0;

        for (uint32_t i = 0; i < capacity; i++)
        {
            indices[i + 0] = 0 + offset;
            indices[i + 1] = 1 + offset;
            indices[i + 2] = 2 + offset;

            indices[i + 3] = 2 + offset;
            indices[i + 4] = 3 + offset;
            indices[i + 5] = 0 + offset;

            offset += 4;
        }

        glGenBuffers(1, &renderer_id_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices.data(), GL_STATIC_DRAW);
    }

    IndexBuffer::~IndexBuffer() {
        glDeleteBuffers(1, &renderer_id_);
    }

    void IndexBuffer::bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
    }

    void IndexBuffer::unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
} // namespace engine
