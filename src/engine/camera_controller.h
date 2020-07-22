#ifndef PROJECT_KAPPA_ENGINE_CAMERA_CONTROLLER_H
#define PROJECT_KAPPA_ENGINE_CAMERA_CONTROLLER_H

#include "camera.h"

namespace engine
{
    class CameraController {
    private:
        float zoom_ = 1.0f;
        float aspect_ratio_;

        float translation_speed_ = 1.0f, rotation_speed_ = 180.0f;

        Camera camera_;

        bool rotation_;

    public:
        CameraController(float aspect_ratio, bool rotation = false);

        void update(float delta_time);

        const Camera& get_camera() const { return camera_; }

        float get_zoom() { return zoom_; }
        void set_zoom(float level) { zoom_ = level; }

        float get_aspect_ratio() const { return aspect_ratio_; }
    };
} // namespace engine


#endif // PROJECT_KAPPA_ENGINE_CAMERA_CONTROLLER_H