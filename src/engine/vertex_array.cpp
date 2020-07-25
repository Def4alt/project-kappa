#include "vertex_array.h"
#include "vertex_buffer_layout.h"
#include "vertex_buffer.h"

engine::VertexArray::VertexArray() {
    glGenVertexArrays(1, &renderer_id_);
}

engine::VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &renderer_id_);
}

void engine::VertexArray::add_buffer(const VertexBuffer &vb, const VertexBufferLayout &layout) {
    bind();
    vb.bind();

    const auto& elements = layout.get_elements();
    uint32_t offset = 0;

    for (uint32_t i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];

        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type,
                element.normalized, layout.get_stride(), reinterpret_cast<const void*>(offset));

        offset += element.count * VertexBufferElement::get_size_of_type(element.type);
    }
}

void engine::VertexArray::bind() const {
    glBindVertexArray(renderer_id_);
}

void engine::VertexArray::unbind() const {
    glBindVertexArray(0);
}
