#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include "world-object.hpp"

namespace mia 
{
    class Portrait : public WorldObject
    {
    public:
        Portrait(Vector2 position = Vector2::zero(), Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero()):
            WorldObject(position),
            size(size),
            offset(offset)
        {}

    public:
        Vector2 size;
        Vector2 offset;
    };
}

#endif