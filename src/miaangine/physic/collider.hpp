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

        Collider(float sx, float sy, float ox = 0, float oy = 0):
            size(Vector2(sx, sy)),
            offset(Vector2(ox, oy))
        {}

    public:
        Vector2 size;
        Vector2 offset;

        Vector2 *position = nullptr;
    };
}

#endif