#include "BatchRenderer.hpp"
#include "Renderer.hpp"
#include <spdlog/spdlog.h>

namespace engine
{
    void BatchRenderer::draw(Rect rect, uint32_t texture_id)
    {
        if (data_.ib->get_count() >= MAX_INDEX_COUNT || data_.texture_slot_index > 31)
        {
            end_batch();
            flush();
            begin_batch();
        }

        glm::vec4 color(1.0f, 1.0f, 1.0f, 1.0f);

        float texture_index = 0.0f;
        for (uint32_t i = 1; i < data_.texture_slot_index; i++)
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

        data_.quad_buffer_ptr = Vertex::create_quad(data_.quad_buffer_ptr, rect, texture_index, color);

        data_.ib->set_count(data_.ib->get_count() + 6);
    };

    void BatchRenderer::init()
    {
        if (data_.quad_buffer != nullptr)
        {
            spdlog::warn("Tried to init batch renderer more than once");
            return;
        }

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

        uint32_t color = 0xfff;
        data_.white_texture = new Texture(color);
        data_.white_texture->bind(0);

        data_.texture_slots[0] = data_.white_texture->get_renderer_id();

        for (uint32_t i = 1; i < MAX_TEXTURES; i++)
        {
            data_.texture_slots[i] = 0;
        }
    }

    void BatchRenderer::shutdown()
    {
        delete data_.vao;
        delete data_.vb;
        delete data_.ib;
        delete data_.white_texture;
        delete[] data_.quad_buffer;
    }

    void BatchRenderer::begin_batch()
    {
        data_.quad_buffer_ptr = data_.quad_buffer;
    }

    void BatchRenderer::end_batch()
    {
        GLsizeiptr size = (uint8_t *)data_.quad_buffer_ptr - (uint8_t *)data_.quad_buffer;
        data_.vb->bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data_.quad_buffer);
    }

    void BatchRenderer::flush()
    {
        for (uint32_t i = 0; i < data_.texture_slot_index; i++)
            glBindTextureUnit(i, data_.texture_slots[i]);

        Renderer::draw(*data_.vao, *data_.ib);

        data_.ib->set_count(0);
        data_.texture_slot_index = 1;
    }
} // namespace engine
