#ifndef PROJECT_KAPPA_ENGINE_INDEX_BUFFER_H
#define PROJECT_KAPPA_ENGINE_INDEX_BUFFER_H

#include <cstdint>

namespace engine {
    class IndexBuffer {
    public:
        IndexBuffer(uint32_t capacity);
        ~IndexBuffer();

        void bind() const;
        void unbind() const;

        uint32_t get_count() const { return count_; }
        void set_count(uint32_t value) { count_ = value; }

    private:
        uint32_t renderer_id_;
        uint32_t count_;
    };
}


#endif //PROJECT_KAPPA_ENGINE_INDEX_BUFFER_H
