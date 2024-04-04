#include "body.hpp"

#include "physics.hpp"

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
    v2f Body::offset() const
    {
        return _offset;
    }
    v2f Body::size() const
    {
        return _size;
    }
    v2f Body::pivot() const
    {
        return _pivot;
    }
    bool Body::isTrigger() const
    {
        return _trigger;
    }
    bool Body::isStatic() const
    {
        return _static;
    }
    float Body::mass() const
    {
        return _mass;
    }
    v2f Body::velocity() const
    {
        return _velocity;
    }
    v2f Body::force() const
    {
        return _force;
    }
    rect Body::getRect() const
    {
        rect res = rect();
        res.siz.x = _size.x * _master->scale().x;
        res.siz.y = _size.y * _master->scale().y;
        res.pos.x = _master->position().x + _offset.x - (_pivot.x * res.siz.x); 
        res.pos.y = _master->position().y + _offset.y - (_pivot.y * res.siz.y); 
        return res;
    }

    float& Body::mass()
    {
        return _mass;
    }
    v2f& Body::velocity()
    {
        return _velocity;
    }
    v2f& Body::force()
    {
        return _force;
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
        Physics::Instance().RegisterBody(this);
    }
#pragma endregion
}