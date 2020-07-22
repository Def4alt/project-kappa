#include "batch_renderer.h"

#include "vertex_array.h"
#include "vertex_buffer.h"
#include "index_buffer.h"
#include "vertex_buffer_layout.h"
#include "texture.h"
#include "vertex.h"
#include "renderer.h"
#include <array>

#include "logger.h"

namespace engine
{
    const unsigned MAX_TEXTURES = 32;
    const unsigned MAX_QUADS_COUNT = 1000;
    const unsigned MAX_VERTEX_COUNT = MAX_QUADS_COUNT * 4;
    const unsigned MAX_INDEX_COUNT = MAX_QUADS_COUNT * 6;

    struct BatchRendererData {
        VertexArray *vao = nullptr;
        VertexBuffer *vb = nullptr;
        IndexBuffer *ib = nullptr;

        Texture *white_texture = nullptr;
        unsigned white_texture_slot = 0;

        Vertex *quad_buffer = nullptr;
        Vertex *quad_buffer_ptr = nullptr;

        std::array<unsigned, MAX_TEXTURES> texture_slots;
        unsigned texture_slot_index;

        BatchRenderer::BatchRendererStats stats;
    };

    static BatchRendererData data_;

    void BatchRenderer::init() {
        data_.quad_buffer = new Vertex[MAX_VERTEX_COUNT];

        data_.vao = new VertexArray();
        data_.vb = new VertexBuffer(MAX_VERTEX_COUNT);

        VertexBufferLayout layout;
        layout.push<float>(3);
        layout.push<float>(4);
        layout.push<float>(2);
        layout.push<float>(1);

        data_.vao->add_buffer(*data_.vb, layout);

        data_.ib = new IndexBuffer(MAX_INDEX_COUNT);

        unsigned color = 0xffffffff;
        data_.white_texture = new Texture(color);
        data_.white_texture->bind(0);

        data_.texture_slots[0] = data_.white_texture->get_renderer_id();
        for (unsigned i = 1; i < MAX_TEXTURES; i++)
            data_.texture_slots[i] = 0;
    }

    void BatchRenderer::shutdown() {
        delete data_.vao;
        delete data_.vb;
        delete data_.ib;
        delete data_.white_texture;

        delete[] data_.quad_buffer;
    }

    void BatchRenderer::begin_batch() {
        data_.quad_buffer_ptr = data_.quad_buffer;
    }

    void BatchRenderer::end_batch() {
        GLsizeiptr size = (uint8_t*)data_.quad_buffer_ptr - (uint8_t*)data_.quad_buffer;
        data_.vb->bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data_.quad_buffer);
    }

    void BatchRenderer::flush() {
        for (unsigned i = 0; i < data_.texture_slot_index; i++)
            glBindTextureUnit(i, data_.texture_slots[i]);

        Renderer::draw(*data_.vao, *data_.ib);

        data_.ib->set_count(0);
        data_.texture_slot_index = 1;
        data_.stats.draw_count++;
    }

    void BatchRenderer::draw_quad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color) {
        if (data_.ib->get_count() >= MAX_INDEX_COUNT) {
            end_batch();
            flush();
            begin_batch();
        }

        float texture_index = 0.0f;
        data_.quad_buffer_ptr = Vertex::create_quad(data_.quad_buffer_ptr, position, color, texture_index, size);

        data_.ib->set_count(data_.ib->get_count() + 6);
        data_.stats.quad_count++;

    }

    void BatchRenderer::draw_quad(const glm::vec3& position, const glm::vec2& size, float texture_id) {
        if (data_.ib->get_count() >= MAX_INDEX_COUNT || data_.texture_slot_index > 31) {
            end_batch();
            flush();
            begin_batch();
        }

        glm::vec4 color(1.0f, 1.0f, 1.0f, 1.0f);

        float texture_index = 0.0f;
        for (unsigned i = 1; i < data_.texture_slot_index; i++)
        {
            if (data_.texture_slots[i] == texture_id)
            {
                texture_index = (float)i;
                break;
            }
        }

        if (texture_index == 0.0f)
        {
            texture_index = (float)data_.texture_slot_index;
            data_.texture_slots[data_.texture_slot_index] = texture_id;
            data_.texture_slot_index++;
        }

        data_.quad_buffer_ptr = Vertex::create_quad(data_.quad_buffer_ptr, position, color, texture_index, size);

        data_.ib->set_count(data_.ib->get_count() + 6);
        data_.stats.quad_count++;
    }

    void BatchRenderer::reset_stats() {
        data_.stats.draw_count = 0;
        data_.stats.quad_count = 0;
    }

    const BatchRenderer::BatchRendererStats& BatchRenderer::get_stats() {
        return data_.stats;
    }
} // namespace engine