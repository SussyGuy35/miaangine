#include "body.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    Body::Body(float mass, vector2 initForce):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _velocity(vector2::zero()),
        _force(initForce),
        _mass(mass),
        _master(nullptr)
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
            mia::debug.Error("[Body] access denied: [master] Null reference"); //FIXME
            // return *_master; //FIXME
        }

        return _master;
    }

    vector2 Body::AddForce(vector2 force)
    {
        _force += force;
        return _force;
    }

    vector2 Body::AddAcceleration(vector2 acceleration)
    {
        return AddForce(acceleration * _mass);
    }

    void Body::ShiftMaster(WorldObject *master)
    {
        this->_master = master;
    }
}