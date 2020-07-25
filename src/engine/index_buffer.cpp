#include "index_buffer.h"
#include "debug.h"
#include <GL/glew.h>

engine::IndexBuffer::IndexBuffer(const uint32_t capacity)
    : count_(0) {
    ASSERT(sizeof(uint32_t) == sizeof(GLuint))

    uint32_t indices[capacity];
    uint32_t offset = 0;
    for (int i = 0; i < capacity; i += 6)
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
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

engine::IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &renderer_id_);
}

void engine::IndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
}

void engine::IndexBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
