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

    #pragma region Non-const attributes
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
            mia::debug.Error("[Body(%s)] Access denied: [master] Null reference; Return null. ", name().str());
        }

        return _master;
    }
    #pragma endregion

    #pragma region Const attributes
    const string& Body::name() const
    {
        return (!_master ? _ucName : _master->name);
    }
    const vector2& Body::position() const
    {
        return (!_master ? _ucPosition : _master->position());
    }
    const vector2& Body::velocity() const
    {
        return _velocity;
    }
    const vector2& Body::force() const
    {
        return _force;
    }
    const float& Body::mass() const
    {
        return _mass;
    }
    const WorldObject* Body::master() const
    {
        if (!_master) 
        {
            mia::debug.Error("[Body(%s)] Access denied: [master] Null reference; Return null. ", name().str());
        }

        return _master;
    }
    #pragma endregion

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