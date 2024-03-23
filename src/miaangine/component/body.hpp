#ifndef _MIA_BODY_HPP
#define _MIA_BODY_HPP

#include "object/object.hpp"

#include <SDL.h>
#include "util/math.hpp"
#include <string>

namespace mia
{
    class Body
    {
    public:
        Body(float mass = 1, Vector2<> initForce = Vector2<>::zero());

        virtual ~Body();

    private:
        // Attributes
        bool _isActive;
        Object *_master;

        float _mass;
        Vector2<> _velocity;
        Vector2<> _force;
    
    public:
        // Attributes accessing
        bool isActive() const;
        const Object& master() const;
        const float& mass() const;
        const Vector2<>& velocity() const;
        const Vector2<>& force() const;

        bool SetActive(bool newState);
        Object& master();
        float& mass() const;
        Vector2<>& velocity();
        Vector2<>& force();

        // Methods
        Vector2 AddForce(Vector2<> force);
        Vector2 AddAcceleration(Vector2<> acceleration);
    };
}

#endif