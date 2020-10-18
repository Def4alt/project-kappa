#ifndef KAPPA_ENGINE_INDEX_BUFFER_HPP
#define KAPPA_ENGINE_INDEX_BUFFER_HPP

#include <stdint.h>

namespace engine
{
    class IndexBuffer
    {
    public:
        IndexBuffer(const uint32_t capacity);
        ~IndexBuffer();

        void bind() const;
        void unbind() const;

        [[nodiscard]] constexpr auto get_count() const noexcept { return count_; }
        constexpr auto set_count(uint32_t value) noexcept { count_ = value; }

    protected:
        uint32_t renderer_id_;
        uint32_t count_;
    };
} // namespace engine

#endif // KAPPA_ENGINE_INDEX_BUFFER_HPP