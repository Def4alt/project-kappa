#ifndef KAPPA_ENGINE_TEXTURE_HPP
#define KAPPA_ENGINE_TEXTURE_HPP

#include <string>
#include <stdint.h>

namespace engine
{
    class Texture
    {
    public:
        Texture(const std::string &filepath);
        Texture(const uint32_t color);

        ~Texture();

        void bind(uint32_t slot = 0) const;
        void unbind() const;

        [[nodiscard]] constexpr auto get_width() const { return width_; }
        [[nodiscard]] constexpr auto get_height() const { return height_; }
        [[nodiscard]] constexpr auto get_renderer_id() const { return renderer_id_; }

    protected:
        uint32_t renderer_id_;
        std::string filepath_;
        unsigned char *local_buffer_;
        int width_, height_, bpp_;
    };
} // namespace engine

#endif // KAPPA_ENGINE_TEXTURE_HPP