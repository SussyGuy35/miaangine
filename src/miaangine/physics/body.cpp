#include "body.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    Body::Body(float mass, Vector2 initForce):
        _ucName("unclaimed"),
        _ucPosition(Vector2::zero()),
        _velocity(Vector2::zero()),
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
    Vector2& Body::position() 
    {
        return (!_master ? _ucPosition : _master->position());
    }
    Vector2& Body::velocity()
    {
        return _velocity;
    }
    Vector2& Body::force()
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
    const Vector2& Body::position() const
    {
        return (!_master ? _ucPosition : _master->position());
    }
    const Vector2& Body::velocity() const
    {
        return _velocity;
    }
    const Vector2& Body::force() const
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

    Vector2 Body::AddForce(Vector2 force)
    {
        _force += force;
        return _force;
    }

    Vector2 Body::AddAcceleration(Vector2 acceleration)
    {
        return AddForce(acceleration * _mass);
    }

    void Body::ShiftMaster(WorldObject *master)
    {
        this->_master = master;
    }
}