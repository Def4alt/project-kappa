#include <GL/glew.h>
#include "vertex_buffer.h"
#include "error.h"

VertexBuffer::VertexBuffer(const void *data, unsigned int size) {
    GL_WRAP(glGenBuffers(1, &renderer_id_))
    GL_WRAP(glBindBuffer(GL_ARRAY_BUFFER, renderer_id_))
    GL_WRAP(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW))
}

VertexBuffer::~VertexBuffer() {
    GL_WRAP(glDeleteBuffers(1, &renderer_id_))
}

void VertexBuffer::bind() const {
    GL_WRAP(glBindBuffer(GL_ARRAY_BUFFER, renderer_id_))
}

void VertexBuffer::unbind() const {
    GL_WRAP(glBindBuffer(GL_ARRAY_BUFFER, 0))
}
