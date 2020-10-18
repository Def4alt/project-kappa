#include "Vertex.hpp"

namespace engine
{
    Vertex *Vertex::create_quad(Vertex *target, Rect rect, float tex_id, glm::vec4 color)
    {
        glm::vec3 pos(rect.x, rect.y, 0.0f);

        target->position = pos;
        target->color = color;
        target->tex_coords = glm::vec2(0.0f, 0.0f);
        target->tex_id = tex_id;
        target++;

        target->position = glm::vec3(pos.x + rect.width, pos.y, pos.z);
        target->color = color;
        target->tex_coords = glm::vec2(1.0f, 0.0f);
        target->tex_id = tex_id;
        target++;

        target->position = glm::vec3(pos.x + rect.width, pos.y + rect.height, pos.z);
        target->color = color;
        target->tex_coords = glm::vec2(1.0f, 1.0f);
        target->tex_id = tex_id;
        target++;

        target->position = glm::vec3(pos.x, pos.y + rect.height, pos.z);
        target->color = color;
        target->tex_coords = glm::vec2(0.0f, 1.0f);
        target->tex_id = tex_id;
        target++;

        return target;
    }
} // namespace engine
