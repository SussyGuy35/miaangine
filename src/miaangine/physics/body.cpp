#include "body.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    Body::Body(vector2 size, vector2 offset):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        size(size),
        offset(offset),
        _master(nullptr),
        velocity(vector2::zero()),
        colliding(false)
    {}

    Body::Body(float sx, float sy, float ox, float oy):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        size(vector2(sx, sy)),
        offset(vector2(ox, oy)),
        _master(nullptr),
        velocity(vector2::zero()),
        colliding(false)
    {}

    Body::~Body()
    {}

    const string& Body::name() const
    {
        return (!_master ? _ucName : _master->name);
    }

    const vector2& Body::position() const
    {
        return (!_master ? _ucPosition : _master->position);
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

    void Body::ShiftMaster(WorldObject *master)
    {
        this->_master = master;
    }
}