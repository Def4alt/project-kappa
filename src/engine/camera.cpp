#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>

engine::Camera::Camera(float left, float right, float bottom, float top) {
    proj_ = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
    view_ = glm::mat4(1.0f);

    view_proj_ = proj_ * view_;
}

void engine::Camera::set_projection_matrix(float left, float right, float bottom, float top) {
    proj_ = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);

    view_proj_ = proj_ * view_;
}

void engine::Camera::recalculate_view_matrix() {
    auto transform = glm::translate(glm::mat4(1.0f), pos_)
        * glm::rotate(glm::mat4(1.0f), glm::radians(rotation_), glm::vec3(0, 0, 1));
    
    view_ = glm::inverse(transform);
    view_proj_ = proj_ * view_;
}