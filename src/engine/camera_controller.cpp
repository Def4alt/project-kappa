#include "camera_controller.h"
#include "event.h"
#include "logger.h"

engine::CameraController::CameraController(float aspect_ratio, bool rotation)
    : aspect_ratio_(aspect_ratio), 
    camera_(-aspect_ratio_ * zoom_ * 1000, aspect_ratio_ * zoom_ * 1000, -zoom_ * 1000, zoom_ * 1000),
    rotation_(rotation) {
}

void engine::CameraController::update(float delta_time) {
    auto pos = camera_.get_position();
    glm::vec3 move(0.0f, 0.0f, 0.0f);

    if (Event::is_pressed(SDLK_w))
        move.y += translation_speed_;

    if (Event::is_pressed(SDLK_a))
        move.x -= translation_speed_;

    if (Event::is_pressed(SDLK_s))
        move.y -= translation_speed_;

    if (Event::is_pressed(SDLK_d))
        move.x += translation_speed_;

    if (glm::length(move) > 0)
        camera_.set_position(pos + move * delta_time);

    if (Event::is_pressed(SDLK_q))
        set_zoom(get_zoom() + 0.01f * delta_time);

    if (Event::is_pressed(SDLK_e)) {
        auto zoom = get_zoom() - 0.01f * delta_time;
        zoom = std::max(zoom, 0.25f);
        set_zoom(zoom);
    }
}