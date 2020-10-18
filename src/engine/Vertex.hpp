#ifndef KAPPA_ENGINE_VERTEX_HPP
#define KAPPA_ENGINE_VERTEX_HPP

#include <glm/glm.hpp>
#include "DefaultTypes.hpp"

namespace engine
{
    struct Vertex
    {
        glm::vec3 position;
        glm::vec4 color;
        glm::vec2 tex_coords;
        float tex_id;

        static Vertex *create_quad(Vertex *target, Rect rect, float tex_id, glm::vec4 color);
    };
} // namespace engine

#endif // KAPPA_ENGINE_VERTEX_HPP