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
        Body(float mass = 1, Vector2 initForce = Vector2::zero());

        virtual ~Body();

    private:
        string _ucName;
        Vector2 _ucPosition;

        Vector2 _velocity;
        Vector2 _force;
        float _mass;
        WorldObject *_master;

    public:
        string& name();
        Vector2& position();
        Vector2& velocity();
        Vector2& force();
        float& mass();
        WorldObject* master();

        const string& name() const;
        const Vector2& position() const;
        const Vector2& velocity() const;
        const Vector2& force() const;
        const float& mass() const;
        const WorldObject* master() const;

        Vector2 AddForce(Vector2 force);
        Vector2 AddAcceleration(Vector2 acceleration);
        
        void ShiftMaster(WorldObject *master);
    };
}

#endif