#ifndef PROJECT_KAPPA_RENDERER_H
#define PROJECT_KAPPA_RENDERER_H


#include "vertex_array.h"
#include "index_buffer.h"
#include "shader.h"

class Renderer {
public:
    void clear() const;
    void draw(const VertexArray& vao, const IndexBuffer& ib, const Shader& shader) const;
};


#endif //PROJECT_KAPPA_RENDERER_H
