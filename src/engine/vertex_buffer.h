#ifndef PROJECT_KAPPA_ENGINE_VERTEX_BUFFER_H
#define PROJECT_KAPPA_ENGINE_VERTEX_BUFFER_H

#include "vertex.h"
#include <GL/glew.h>

namespace engine {
    class VertexBuffer {
    public:
        VertexBuffer(uint32_t capacity, const void *data = nullptr, const uint32_t type = GL_DYNAMIC_DRAW);
        ~VertexBuffer();

        void bind() const;
        void unbind() const;

    private:
        uint32_t renderer_id_;
    };
}

#endif //PROJECT_KAPPA_ENGINE_VERTEX_BUFFER_H
