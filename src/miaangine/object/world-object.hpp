#ifndef _MIA_WORLD_OBJECT_HPP
#define _MIA_WORLD_OBJECT_HPP

#include <vector>

#include "game-object.hpp"

#include "util/math.hpp"

namespace mia 
{
    class Portrait;
    class Body;
    class WorldObject : public GameObject
    {
    public:
        WorldObject(const char* name = "object", Vector2 position = Vector2::zero());
        WorldObject(const char* name, float x, float y);

        virtual ~WorldObject();

    private:
        Vector2 _position;

        std::vector<Portrait*> _portraits;
        Body *_body;

    public:
        Vector2& position();
        Portrait& portrait(int index = 0);
        Body& body();

        const Vector2& position() const;
        const Portrait& portrait(int index = 0) const;
        const Body& body() const;

        Portrait& AttachPortrait(Portrait *portrait);
        Body& AttachBody(Body *body);

        Portrait& MakePortrait(const char* dir = "", Vector2 scale = Vector2::one(), Vector2 offset = Vector2::zero());
        Portrait& MakePortrait(const char* dir, float sx, float sy, float ox = 0, float oy = 0);
        Portrait& MakePortrait(Vector2 scale, Vector2 offset = Vector2::zero());
        Portrait& MakePortrait(float sx, float sy, float ox = 0, float oy = 0);

        Body& MakeBody(float mass = 1, Vector2 initForce = Vector2::zero());
    };
}

#endif