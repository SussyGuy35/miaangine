#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include "util/math.hpp"

#include "object/world-object.hpp"

// namespace mia 
// {
    class mia::Portrait
    {
    public:
        Portrait(Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero());
        Portrait(float sx, float sy, float ox = 0, float oy = 0);

    public:
        Vector2 size;
        Vector2 offset;

        WorldObject *master;

        virtual void Log();
    };
// }

#endif