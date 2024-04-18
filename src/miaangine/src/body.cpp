#include "body.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Body::Body(Object *master, int type, v2f size, v2f pivot, v2f offset):
        _master(master),
        _type(type),
        _size(size),
        _offset(offset),
        _pivot(pivot),
        _mass(1),
        _velocity(v2f::zero()),
        _force(v2f::zero())
    {
        _master->SetBody(this);
    }

    Body::~Body()
    {}
#pragma endregion

#pragma region GetSet method
    const Object& Body::master() const
    {
        if (!_master)
        {
            // FIXME
        }
        
        return *_master;
    }
    int Body::getType() const
    {
        return _type;
    }
    const v2f& Body::size() const
    {
        return _size;
    }
    const v2f& Body::pivot() const
    {
        return _pivot;
    }
    const v2f& Body::offset() const
    {
        return _offset;
    }
    bool Body::IsTriggered() const 
    {
        return _triggered;
    }
    const float& Body::mass() const
    {
        return _mass;
    }
    const v2f& Body::velocity() const
    {
        return _velocity;
    }
    const v2f& Body::force() const
    {
        return _force;
    }

    Object& Body::master()
    {
        if (!_master)
        {
            // FIXME
        }
        
        return *_master;
    }
    int Body::setType(int newType)
    {
        return _type;
    }
    v2f& Body::size()
    {
        return _size;
    }
    v2f& Body::pivot()
    {
        return _pivot;
    }
    v2f& Body::offset()
    {
        return _offset;
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
    Object& Body::ChangeMaster(Object *newMaster)
    {
        if (!newMaster)
        {
            // FIXME
        }
        
        _master = newMaster;
        return *_master;
    }

    rect Body::GetRect() const
    {
        rect res = rect();
        res.siz = _size;
        res.pos = master().position() + _offset - v2f(_pivot.x * res.siz.x, _pivot.y * res.siz.y);
        return res;
    }
    bool Body::SetTriggered(bool newState)
    {
        return _triggered = newState;
    }

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
        return "Body";
    }
#pragma endregion
}