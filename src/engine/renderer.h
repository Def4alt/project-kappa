#ifndef PROJECT_KAPPA_ENGINE_RENDERER_H
#define PROJECT_KAPPA_ENGINE_RENDERER_H


#include "vertex_array.h"
#include "index_buffer.h"
#include "shader.h"

namespace engine {
    class Renderer {
    public:
        static void clear();
        static void draw(const VertexArray& vao, const IndexBuffer& ib);
    };
}


#endif //PROJECT_KAPPA_ENGINE_RENDERER_H
