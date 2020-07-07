#ifndef PROJECT_KAPPA_VERTEX_ARRAY_H
#define PROJECT_KAPPA_VERTEX_ARRAY_H


#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

class VertexArray {
public:
    VertexArray();
    ~VertexArray();

    void add_buffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void bind() const;
    void unbind() const;

private:
    unsigned renderer_id_;
};


#endif //PROJECT_KAPPA_VERTEX_ARRAY_H
