#ifndef _MIA_GAME_OBJECT_HPP
#define _MIA_GAME_OBJECT_HPP

#include "event/event-manager.hpp"

#include "util/vector.hpp"

namespace mia 
{
    class WorldObject : public IEventListener
    {
    public:
        WorldObject(Vector2 position = Vector2::zero()):
            position(position)
        {}

        ~WorldObject();

    public:
        Vector2 position;
    };
}

#endif