#ifndef _MIA_COLLIDER_HPP
#define _MIA_COLLIDER_HPP

#include "util/math.hpp"

#include "object/world-object.hpp"

// namespace mia
// {
    class mia::Body
    {
    public:
        Body(Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero());
        Body(float sx, float sy, float ox = 0, float oy = 0);

    public:
        Vector2 size;
        Vector2 offset;

        WorldObject *master;

        bool colliding;

        virtual void Log();
    };
// }

#endif