#include <GL/glew.h>
#include "vertex_buffer.h"
#include "error.h"
#include "vertex.h"

engine::VertexBuffer::VertexBuffer(unsigned int capacity, const void *data, const unsigned type) {
    glGenBuffers(1, &renderer_id_);
    glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
    glBufferData(GL_ARRAY_BUFFER, capacity * sizeof(engine::Vertex), data, type);
}

engine::VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &renderer_id_);
}

void engine::VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
}

void engine::VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
