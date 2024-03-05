#ifndef _MIA_GAME_OBJECT_HPP
#define _MIA_GAME_OBJECT_HPP

#include <SDL.h>
#include <vector>

#include "event/event-listener-interface.hpp"

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

    protected:
        std::vector<Portrait*> _portraits;
        std::vector<Body*> _bodies;

    public:
        Portrait *portrait(int index = 0);
        Body *body(int index = 0);

        void AttachPortrait(Portrait *portrait);
        void AttachBody(Body *body);

        void MakePortrait(Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero());
        void MakePortrait(float sx, float sy, float ox = 0, float oy = 0);

        void MakeBody(Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero());
        void MakeBody(float sx, float sy, float ox = 0, float oy = 0);

        virtual void Log();
    };
}

#endif