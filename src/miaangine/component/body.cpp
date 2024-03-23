#include "body.hpp"

namespace mia
{
    #pragma region Constructor_Destructor
    Body::Body(Object *master, float mass, Vector2<> initForce):
        _isActive(true),
        _master(master),
        _mass(mass),
        _velocity(Vector2<>::zero()),
        _force(initForce)
    {}

    Body::~Body()
    {}
    #pragma endregion

    #pragma region Attributes accessing
    bool Body::isActive() const 
    { 
        return _isActive;
    }
    const Object& Body::master() const 
    { 
        return *_master; 
    }
    const float& Body::mass() const 
    {
        return _mass;
    }
    const Vector2<>& Body::velocity() const 
    {
        return _velocity;
    }
    const Vector2<>& Body::force() const 
    {
        return _force;
    }

    bool Body::SetActive(bool newState) 
    { 
        return _isActive = newState; 
    }
    Object& Body::master() 
    { 
        return *_master; 
    }
    float& Body::mass()
    {
        return _mass;
    }
    Vector2<>& Body::velocity()
    {
        return _velocity;
    }
    Vector2<>& Body::force()
    {
        return _force;
    }
    #pragma endregion

    #pragma region Methods
    const Vector2<>& Body::AddForce(Vector2<> force)
    {
        _force += force;
        return _force;
    }
    const Vector2<>& Body::AddAcceleration(Vector2<> acceleration)
    {
        _force += acceleration * _mass;
        return _force;
    }
    #pragma endregion
}