#ifndef KAPPA_ENGINE_DEFAULT_TYPES_HPP
#define KAPPA_ENGINE_DEFAULT_TYPES_HPP

#include <glm/glm.hpp>

namespace engine
{
    union Rect
    {
        int x;
        int y;
        int width;
        int height;
    };

    
} // namespace engine


#endif // KAPPA_ENGINE_DEFAULT_TYPES_HPP