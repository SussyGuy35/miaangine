#include "body.hpp"

#include "debug/debug-manager.hpp"

namespace mia
{
    Body::Body(vector2 size, vector2 offset):
        _unclaimName("unclaimed"),
        _unclaimPosition(vector2::zero()),
        size(size),
        offset(offset),
        _master(nullptr),
        velocity(vector2::zero()),
        colliding(false)
    {}

    Body::Body(float sx, float sy, float ox, float oy):
        _unclaimName("unclaimed"),
        _unclaimPosition(vector2::zero()),
        size(vector2(sx, sy)),
        offset(vector2(ox, oy)),
        _master(nullptr),
        velocity(vector2::zero()),
        colliding(false)
    {}

    Body::~Body()
    {
        delete(name);
        delete(position);
    }

    WorldObject *Body::master()
    {
        if (!_master) 
        {
            mia::DebugManager::Instance()->Error("[Body] access denied: [master] Null reference"); //FIXME
            return nullptr;
        }

        return _master;
    }

    void Body::ShiftMaster(WorldObject *master)
    {
        this->_master = master;
        name = &(master->name);
        position = &(master->position);
    }
}