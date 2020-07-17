#include <GL/glew.h>
#include "vertex_buffer.h"
#include "error.h"

VertexBuffer::VertexBuffer(unsigned int capacity, const void *data, const unsigned type) {
    glGenBuffers(1, &renderer_id_);
    glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
    glBufferData(GL_ARRAY_BUFFER, capacity * sizeof(Vertex), data, type);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &renderer_id_);
}

void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
}

void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
