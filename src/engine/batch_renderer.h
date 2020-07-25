#ifndef PROJECT_KAPPA_ENGINE_BATCH_RENDERER_H
#define PROJECT_KAPPA_ENGINE_BATCH_RENDERER_H

#include <glm/glm.hpp>

namespace engine {
    class BatchRenderer {
    public:
        static void init();
        static void shutdown();

        static void begin_batch();
        static void end_batch();
        static void flush();

        static void draw_quad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
        static void draw_quad(const glm::vec3& position, const glm::vec2& size, float texture_id);

        struct BatchRendererStats
        {
            uint32_t draw_count = 0;
            uint32_t quad_count = 0;
        };

        static void reset_stats();
        static const BatchRendererStats& get_stats();
    };
}

#endif // PROJECT_KAPPA_ENGINE_BATCH_RENDERER_H