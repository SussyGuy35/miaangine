#include "portrait.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    Portrait::Portrait(vector2 size, vector2 offset):
        _unclaimPosition(vector2::zero()),
        size(size),
        offset(offset),
        color({255, 255, 255, 255}),
        _master(nullptr)
    {}

    Portrait::Portrait(float sx, float sy, float ox, float oy):
        _unclaimPosition(vector2::zero()),
        size(vector2(sx, sy)),
        offset(vector2(ox, oy)),
        color({255, 255, 255, 255}),
        _master(nullptr)
    {}

    Portrait::~Portrait()
    {
        delete(name);
        delete(position);
    }

    WorldObject *Portrait::master()
    {
        if (!_master) 
        {
            mia::DebugManager::Instance().Error("[Portrait] access denied: [master] Null reference"); //FIXME
            return nullptr;
        }

        return _master;
    }

    void Portrait::ShiftMaster(WorldObject *master)
    {
        this->_master = master;
        name = &(master->name);
        position = &(master->position);
    }
}