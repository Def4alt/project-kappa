#ifndef PROJECT_KAPPA_ENGINE_CAMERA_H
#define PROJECT_KAPPA_ENGINE_CAMERA_H

#include <glm/glm.hpp>

namespace engine
{
    class Camera
    {
    private:
        glm::mat4 proj_, view_, view_proj_;

        glm::vec3 pos_ = { 0.0f, 0.0f, 0.0f };
        float rotation_ = 0.0f;
    public:
        Camera(float left, float right, float bottom, float top);

        const glm::mat4& get_projection_matrix() const { return proj_; }
        void set_projection_matrix(float left, float right, float bottom, float top);

        const glm::mat4& get_view_matrix() const { return proj_; }
        const glm::mat4& get_view_projection_matrix() const { return view_proj_; }
        
        const glm::vec3& get_position() const { return pos_; }
        void set_position(const glm::vec3& position) { pos_ = position; recalculate_view_matrix(); }

        float get_rotation() const { return rotation_; }
        void set_rotation(float rotation) { rotation_ = rotation; recalculate_view_matrix(); }

    private:
        void recalculate_view_matrix();
    };
} // namespace engine


#endif // PROJECT_KAPPA_ENGINE_CAMERA_H