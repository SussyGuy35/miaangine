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
        WorldObject(const char* name = "object", vector2 position = vector2::zero());
        WorldObject(const char* name, float x, float y);

        virtual ~WorldObject();

    private:
        vector2 _position;

        std::vector<Portrait*> _portraits;
        std::vector<Body*> _bodies;

    public:
        vector2& position();

        Portrait& portrait(int index = 0);
        Body& body(int index = 0);

        Portrait& AttachPortrait(Portrait *portrait);
        Body& AttachBody(Body *body);

        Portrait& MakePortrait(const char* dir = "", vector2 scale = vector2::one(), vector2 offset = vector2::zero());
        Portrait& MakePortrait(const char* dir, float sx, float sy, float ox, float oy);
        Portrait& MakePortrait(vector2 scale, vector2 offset = vector2::zero());
        Portrait& MakePortrait(float sx, float sy, float ox = 0, float oy = 0);

        Body& MakeBody(vector2 size = vector2::zero(), vector2 offset = vector2::zero());
        Body& MakeBody(float sx, float sy, float ox = 0, float oy = 0);
    };
}

#endif