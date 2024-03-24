#ifndef _MIA_BODY_HPP
#define _MIA_BODY_HPP

#include "object/object.hpp"

#include "util/math.hpp"

namespace mia
{
    class Body
    {
    private:
        friend class Object;
        
        Body(Object *master, float mass, Vector2<> initForce);

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
        float& mass();
        Vector2<>& velocity();
        Vector2<>& force();

        // Methods
        const Vector2<>& AddForce(Vector2<> force);
        const Vector2<>& AddForce(float x, float y);
        const Vector2<>& AddAcceleration(Vector2<> acceleration);
        const Vector2<>& AddAcceleration(float x, float y);
    };
}

#endif