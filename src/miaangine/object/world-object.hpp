#ifndef _MIA_GAME_OBJECT_HPP
#define _MIA_GAME_OBJECT_HPP

#include <memory>

#include "event/event-manager.hpp"

#include "util/math.hpp"

#include "graphic/portrait.hpp"
#include "physic/collider.hpp"

namespace mia 
{
    class WorldObject : public IEventListener
    {
    public:
        WorldObject(Vector2 position = Vector2::zero()):
            position(position)
        {}
        WorldObject(float x, float y):
            position(Vector2(x, y))
        {}

        ~WorldObject()
        {
            delete(portrait);
            delete(collider);
        }

    public:
        Vector2 position;

        Portrait *portrait;
        Collider *collider;

    public:
        void MakePortrait(Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero());
        void MakePortrait(float sx, float sy, float ox = 0, float oy = 0);

        void MakeCollider(Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero());
        void MakeCollider(float sx, float sy, float ox = 0, float oy = 0);
    };
}

#endif