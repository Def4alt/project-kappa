#include "vertex.h"

Vertex* Vertex::create_quad(Vertex* target, glm::vec3 pos, glm::vec4 color, float tex_id, float size) {
    target->position = pos;
    target->color = color;
    target->tex_coords = glm::vec2(0.0f, 0.0f);
    target->tex_id = tex_id;
    target++;

    target->position = glm::vec3(pos.x + size, pos.y, pos.z);
    target->color = color;
    target->tex_coords = glm::vec2(1.0f, 0.0f);
    target->tex_id = tex_id;
    target++;

    target->position = glm::vec3(pos.x + size, pos.y + size, pos.z);
    target->color = color;
    target->tex_coords = glm::vec2(1.0f, 1.0f);
    target->tex_id = tex_id;
    target++;
    
    target->position = glm::vec3(pos.x, pos.y + size, pos.z);
    target->color = color;
    target->tex_coords = glm::vec2(0.0f, 1.0f);
    target->tex_id = tex_id;
    target++;
    
    return target;
}