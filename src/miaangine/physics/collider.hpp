#ifndef _MIA_COLLIDER_HPP
#define _MIA_COLLIDER_HPP

#include "util/math.hpp"

#include "body.hpp"
#include "object/world-object.hpp"

namespace mia
{
    class Collider
    {
    public:
        Collider(vector2 size = vector2::zero(), vector2 offset = vector2::zero());
        Collider(float sx, float sy, float ox = 0, float oy = 0);

        virtual ~Collider();

    private:
        string _ucName;
        vector2 _ucPosition;

        vector2 _size;
        vector2 _offset;

        Body* _body;
        WorldObject *_master;

    public:
        string& name();
        vector2& position();
        vector2& size();
        vector2& offset();

        Body* body();
        WorldObject* master();
        
        bool CheckColliding(Collider *other);

        void ShiftBody(Body *body);
        void ShiftMaster(WorldObject *master);
    };
}

#endif