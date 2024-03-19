#include "body.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    Body::Body(vector2 size, vector2 offset):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _size(size),
        _offset(offset),
        _velocity(vector2::zero()),
        _force(vector2::zero()),
        _mass(1),
        _master(nullptr),
        colliding(false)
    {}

    Body::Body(float sx, float sy, float ox, float oy):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _size(vector2(sx, sy)),
        _offset(vector2(ox, oy)),
        _velocity(vector2::zero()),
        _force(vector2::zero()),
        _mass(1),
        _master(nullptr),
        colliding(false)
    {}

    Body::~Body()
    {}

    string& Body::name() 
    {
        return (!_master ? _ucName : _master->name);
    }

    vector2& Body::position() 
    {
        return (!_master ? _ucPosition : _master->position());
    }
    vector2& Body::size()
    {
        return _size;
    }
    vector2& Body::offset()
    {
        return _offset;
    }
    vector2& Body::velocity()
    {
        return _velocity;
    }
    vector2& Body::force()
    {
        return _force;
    }
    float& Body::mass()
    {
        return _mass;
    }

    WorldObject* Body::master()
    {
        if (!_master) 
        {
            mia::DebugManager::Instance().Error("[Body] access denied: [master] Null reference"); //FIXME
            // return *_master; //FIXME
        }

        return _master;
    }

    vector2 Body::AddForce(vector2 force)
    {
        _force += force;
        return _force;
    }

    void Body::ShiftMaster(WorldObject *master)
    {
        this->_master = master;
    }
}