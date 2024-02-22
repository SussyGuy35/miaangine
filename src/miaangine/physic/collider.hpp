#ifndef _MIA_COLLIDER_HPP
#define _MIA_COLLIDER_HPP

#include "util/math.hpp"

namespace mia
{
    class Collider
    {
    public:
        Collider(Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero()):
            size(size),
            offset(offset)
        {}

    public:
        Vector2 size;
        Vector2 offset;
    };
}

#endif