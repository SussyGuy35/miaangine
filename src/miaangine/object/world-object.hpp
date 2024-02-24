#ifndef _MIA_GAME_OBJECT_HPP
#define _MIA_GAME_OBJECT_HPP

#include "event/event-manager.hpp"

#include "util/math.hpp"

namespace mia 
{
    class Portrait;
    class Body;
    class WorldObject : public IEventListener
    {
    public:
        WorldObject(Vector2 position = Vector2::zero());
        WorldObject(float x, float y);

        ~WorldObject();

    public:
        Vector2 position;

        Portrait *portrait;
        Body *body;

    public:
        void AttachPortrait(Portrait *portrait);
        void AttachBody(Body *body);

        void MakePortrait(Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero());
        void MakePortrait(float sx, float sy, float ox = 0, float oy = 0);

        void MakeBody(Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero());
        void MakeBody(float sx, float sy, float ox = 0, float oy = 0);
    };
}

#endif