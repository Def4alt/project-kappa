#ifndef KAPPA_ENGINE_SPRITE_HPP
#define KAPPA_ENGINE_SPRITE_HPP

#include <glm/glm.hpp>
#include "Texture.hpp"
#include "DefaultTypes.hpp"
#include <stdint.h>

namespace engine
{
    class Sprite
    {
    public:
        Sprite(Texture texture, Rect rect)
            : renderer_id_(0), texture_(texture), rect_(rect){};

        void draw(uint32_t texture_slot = 0) const;

    protected:
        uint32_t renderer_id_;

        Rect rect_;
        Texture texture_;
    };
} // namespace engine

#endif // KAPA_ENGINE_SPRITE_HPP