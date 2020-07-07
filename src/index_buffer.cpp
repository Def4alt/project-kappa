#include "index_buffer.h"
#include "error.h"
#include <GL/glew.h>

IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count)
    :count_(count) {
    ASSERT(sizeof(unsigned) == sizeof(GLuint))

    GL_WRAP(glGenBuffers(1, &renderer_id_))
    GL_WRAP(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_))
    GL_WRAP(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned), data, GL_STATIC_DRAW))
}

IndexBuffer::~IndexBuffer() {
    GL_WRAP(glDeleteBuffers(1, &renderer_id_))
}

void IndexBuffer::bind() const {
    GL_WRAP(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_))
}

void IndexBuffer::unbind() const {
    GL_WRAP(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0))
}
