#ifndef _MIA_GAME_OBJECT_HPP
#define _MIA_GAME_OBJECT_HPP

#include "event/event-manager.hpp"

#include "util/vector.hpp"

namespace mia 
{
    class GameObject : public IEventListener
    {
    public:
        GameObject(Vector2 position = Vector2::zero()):
            position(position)
        {}

        ~GameObject();

    public:
        Vector2 position;
    };
}

#endif