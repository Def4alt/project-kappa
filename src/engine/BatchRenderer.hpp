#ifndef KAPPA_ENGINE_BATCH_RENDERER_HPP
#define KAPPA_ENGINE_BATCH_RENDERER_HPP

#include <stdint.h>
#include "DefaultTypes.hpp"
#include <array>
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "Texture.hpp"
#include "Vertex.hpp"

namespace engine
{
    const uint32_t MAX_TEXTURES = 32;
    const uint32_t MAX_QUADS_COUNT = 1000;
    const uint32_t MAX_VERTEX_COUNT = MAX_QUADS_COUNT * 4;
    const uint32_t MAX_INDEX_COUNT = MAX_QUADS_COUNT * 6;

    struct BatchRendererData
    {
        VertexArray *vao = nullptr;
        VertexBuffer *vb = nullptr;
        IndexBuffer *ib = nullptr;

        Texture *white_texture = nullptr;
        uint32_t white_texture_slot = 0;

        Vertex *quad_buffer = nullptr;
        Vertex *quad_buffer_ptr = nullptr;

        std::array<uint32_t, MAX_TEXTURES> texture_slots;
        uint32_t texture_slot_index;
    };

    static BatchRendererData data_;

    class BatchRenderer
    {
    public:
        static void init();
        static void shutdown();

        static void begin_batch();
        static void end_batch();
        static void flush();

        static void draw(Rect rect, uint32_t texture_id);
    };
} // namespace engine

#endif // KAPPA_ENGINE_BATCH_RENDERER_HPP