#include "body.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Body::Body(float mass, v2f initForce):
        _mass(mass),
        _velocity(v2f::zero()),
        _force(initForce)
    {}

    Body::~Body()
    {}
#pragma endregion

#pragma region GetSet method
    float Body::mass() const
    {
        return _mass;
    }
    v2f Body::velocity() const
    {
        return _velocity;
    }

    float& Body::mass()
    {
        return _mass;
    }
    v2f& Body::velocity()
    {
        return _velocity;
    }
#pragma endregion

#pragma region Public method
    v2f Body::AddForce(v2f force)
    {
        _force += force;
        return _force;
    }
    v2f Body::AddForce(float x, float y)
    {
        _force += v2f(x, y);
        return _force;
    }

    v2f Body::AddAcceleration(v2f acceleration)
    {
        _force += acceleration * _mass;
        return _force;
    }
    v2f Body::AddAcceleration(float x, float y)
    {
        _force += v2f(x, y) * _mass;
        return _force;
    }
#pragma endregion

#pragma region Inherited method
    int Body::getID() const
    {
        return _ENTITY_BODY;
    }
    const char* Body::ToStr() const
    {
        return "Body(Component)";
    }
    bool Body::Init()
    {
        // TODO
    }
#pragma endregion
}