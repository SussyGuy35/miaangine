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
        Body(float mass = 1, vector2 initForce = vector2::zero());

        virtual ~Body();

    private:
        // Attributes
        bool _isActive;
        Object *_master;

        float _mass;
        vector2<> _velocity;
        vector2<> _force;
    
    public:
        // Attributes accessing
        bool isActive() const;
        const Object& master() const;
        const float& mass() const;
        const vector2<>& velocity() const;
        const vector2<>& force() const;

        bool SetActive(bool newState);
        Object& master();
        float& mass() const;
        vector2<>& velocity();
        vector2<>& force();

        // Methods
        vector2 AddForce(vector2 force);
        vector2 AddAcceleration(vector2 acceleration);
    };
}

#endif