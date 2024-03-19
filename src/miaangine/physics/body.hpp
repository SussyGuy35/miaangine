#ifndef _MIA_COLLIDER_HPP
#define _MIA_COLLIDER_HPP

#include "util/math.hpp"

#include "object/world-object.hpp"

namespace mia
{
    class Collider;
    class Body
    {
    public:
        Body(vector2 size = vector2::zero(), vector2 offset = vector2::zero());
        Body(float sx, float sy, float ox = 0, float oy = 0);

        virtual ~Body();

    private:
        string _ucName;
        vector2 _ucPosition;

        vector2 _velocity;
        vector2 _force;

        float _mass;

        WorldObject *_master;

    public:
        string& name();
        vector2& position();
        vector2& velocity();
        vector2& force();
        float& mass();

        WorldObject* master();

        vector2 AddForce(vector2 force);
        vector2 AddAcceleration(vector2 acceleration);
        
        void ShiftMaster(WorldObject *master);
    };
}

#endif