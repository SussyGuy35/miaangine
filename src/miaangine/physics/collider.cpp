#include "collider.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    Collider::Collider(vector2 size, vector2 offset):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _size(size),
        _offset(offset),
        _body(nullptr),
        _master(nullptr)
    {}
    Collider::Collider(float sx, float sy, float ox = 0, float oy = 0):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _size(vector2(sx, sy)),
        _offset(vector2(ox, oy)),
        _body(nullptr),
        _master(nullptr)
    {}

    Collider::~Collider()
    {}

    string& Collider::name()
    {
        return (!_master ? _ucName : _master->name);
    }
    vector2& Collider::position()
    {
        return (!_master ? _ucPosition : _master->position());
    }
    vector2& Collider::size()
    {
        return _size;
    }
    vector2& Collider::offset()
    {
        return _offset;
    }

    Body* Collider::body()
    {
        if (!_body) 
        {
            mia::debug.Error("[Collider] access denied: [body] Null reference"); //FIXME
        }

        return _body;
    }
    WorldObject* Collider::master()
    {
        if (!_master) 
        {
            mia::debug.Error("[Collider] access denied: [master] Null reference"); //FIXME
        }

        return _master;
    }

    bool Collider::CheckColliding(Collider *other)
    {

    }

    void Collider::ShiftBody(Body *body)
    {
        this->_body = body;
    }
    void Collider::ShiftMaster(WorldObject *master)
    {
        this->_master = master;
    }
}