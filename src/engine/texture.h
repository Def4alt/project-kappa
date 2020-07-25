#ifndef PROJECT_KAPPA_ENGINE_TEXTURE_H
#define PROJECT_KAPPA_ENGINE_TEXTURE_H


#include <string>

namespace engine {
    class Texture {
    public:
        Texture(const std::string& filepath);
        Texture(const uint32_t color);
        ~Texture();

        void bind(uint32_t slot = 0) const;
        void unbind() const;

        inline int get_width() const { return width_; }
        inline int get_height() const { return height_; }
        inline uint32_t get_renderer_id() const { return renderer_id_; }

    private:
        uint32_t renderer_id_;
        std::string filepath_;
        unsigned char* local_buffer_;
        int width_, height_, bpp_;
    };
}


#endif //PROJECT_KAPPA_ENGINE_TEXTURE_H
