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

    public:
        vector2 position;

    protected:
        std::vector<Portrait*> _portraits;
        std::vector<Body*> _bodies;

    public:
        Portrait *portrait(int index = 0);
        Body *body(int index = 0);

        void AttachPortrait(Portrait *portrait);
        void AttachBody(Body *body);

        void MakePortrait(vector2 size = vector2::zero(), vector2 offset = vector2::zero());
        void MakePortrait(float sx, float sy, float ox = 0, float oy = 0);

        void MakeBody(vector2 size = vector2::zero(), vector2 offset = vector2::zero());
        void MakeBody(float sx, float sy, float ox = 0, float oy = 0);
    };
}

#endif