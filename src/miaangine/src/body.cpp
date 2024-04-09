#include "body.hpp"

#include "physics.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Body::Body(BodyType type, v2f size, v2f offset, float mass, v2f initForce):
        _type(type),
        _size(size),
        _offset(offset),
        _pivot(v2f::zero()),
        _trigger(false),
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
        return _type == _BODY_STATIC;
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
    quadtree::Box<float> Body::getRect() const
    {
        quadtree::Box<float> res;
        res.width = _size.x;
        res.height = _size.y;
        res.left = _master->position().x + _offset.x - (_pivot.x * res.width); 
        res.top = _master->position().y + _offset.y - ( _pivot.y * res.height); 
        return res;
    }

    int& Body::setType(bool newState)
    {
        if (_type == _BODY_DYNAMIC && newState == _BODY_STATIC)
        {
            Physics::Instance().RemoveBody(this);
            Physics::Instance().RegisterBody(this); // FIXME
        }

        return _type = newState;
    }
    v2f& Body::offset()
    {
        return _offset;
    }
    v2f& Body::size()
    {
        return _size;
    }
    v2f& Body::pivot()
    {
        return _pivot;
    }
    bool& Body::setTrigger(int newState)
    {
        return _trigger = newState;
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