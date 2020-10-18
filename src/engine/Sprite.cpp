#include "Sprite.hpp"
#include "BatchRenderer.hpp"

namespace engine
{
    void Sprite::draw(uint32_t texture_slot) const
    {
        texture_.bind(texture_slot);

        BatchRenderer::draw(rect_, texture_.get_renderer_id());
    }
} // namespace engine
