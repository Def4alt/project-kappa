#ifndef PROJECT_KAPPA_VERTEX_BUFFER_H
#define PROJECT_KAPPA_VERTEX_BUFFER_H

#include "vertex.h"
#include <GL/glew.h>

namespace engine {
    class VertexBuffer {
    public:
        VertexBuffer(unsigned int capacity, const void *data = nullptr, const unsigned type = GL_DYNAMIC_DRAW);
        ~VertexBuffer();

        void bind() const;
        void unbind() const;

    private:
        unsigned renderer_id_;
    };
}

#endif //PROJECT_KAPPA_VERTEX_BUFFER_H
