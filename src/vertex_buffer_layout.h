#ifndef PROJECT_KAPPA_VERTEX_BUFFER_LAYOUT_H
#define PROJECT_KAPPA_VERTEX_BUFFER_LAYOUT_H

#include <GL/glew.h>
#include <vector>
#include "error.h"

struct VertexBufferElement {
    unsigned type;
    unsigned count;
    unsigned char normalized;

    static unsigned get_size_of_type(unsigned type) {
        switch (type) {
            case GL_FLOAT: return 4;
            case GL_UNSIGNED_INT: return 4;
            case GL_UNSIGNED_BYTE: return 1;
            default:
                ASSERT(false)
        }
    }
};

class VertexBufferLayout {
public:
    VertexBufferLayout()
            : stride_(0) {}

    template<typename T>
    void push(unsigned count);

    inline unsigned get_stride() const { return stride_; }

    inline std::vector<VertexBufferElement> get_elements() const { return elements_; }

private:
    std::vector<VertexBufferElement> elements_;
    unsigned stride_;
};


template<>
inline void VertexBufferLayout::push<float>(unsigned count) {
    elements_.push_back({GL_FLOAT, count, GL_FALSE});
    stride_ += VertexBufferElement::get_size_of_type(GL_FLOAT) * count;
}

template<>
inline void VertexBufferLayout::push<unsigned>(unsigned count) {
    elements_.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    stride_ += VertexBufferElement::get_size_of_type(GL_UNSIGNED_INT) * count;

}

template<>
inline void VertexBufferLayout::push<unsigned char>(unsigned count) {
    elements_.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    stride_ += VertexBufferElement::get_size_of_type(GL_UNSIGNED_BYTE) * count;
}

#endif //PROJECT_KAPPA_VERTEX_BUFFER_LAYOUT_H
