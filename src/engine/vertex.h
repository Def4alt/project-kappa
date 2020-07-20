#ifndef PROJECT_KAPPA_VERTEX_H
#define PROJECT_KAPPA_VERTEX_H

#include "glm/glm.hpp"
#include <array>

namespace engine {
    struct Vertex {
        glm::vec3 position;
        glm::vec4 color;
        glm::vec2 tex_coords;
        float tex_id;

        static Vertex* create_quad(Vertex* target, glm::vec3 pos, glm::vec4 color, float tex_id, float size);
    };
}

#endif // PROJECT_KAPPA_VERTEX_H