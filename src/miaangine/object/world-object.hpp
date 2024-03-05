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

    protected:
        Portrait *_portrait;
        Body *_body;
        // Straight using this var derived class may cause undefined reference error

    public:
        Portrait *portrait();
        Body *body();

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