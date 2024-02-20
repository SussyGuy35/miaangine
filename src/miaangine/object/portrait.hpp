#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include "game-object.hpp"

namespace mia 
{
    class Portrait : public GameObject
    {
    public:
        Portrait(Vector2 position = Vector2::zero(), Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero()):
            GameObject(position),
            size(size),
            offset(offset)
        {}

    public:
        Vector2 size;
        Vector2 offset;
    };
}

#endif