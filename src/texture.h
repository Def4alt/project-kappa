#ifndef PROJECT_KAPPA_TEXTURE_H
#define PROJECT_KAPPA_TEXTURE_H


#include <string>

class Texture {
public:
    Texture(const std::string& filepath);
    ~Texture();

    void bind(unsigned slot = 0) const;
    void unbind() const;

    inline int get_width() const {return width_;}
    inline int get_height() const {return height_;}

private:
    unsigned renderer_id_;
    std::string filepath_;
    unsigned char* local_buffer_;
    int width_, height_, bpp_;
};


#endif //PROJECT_KAPPA_TEXTURE_H
