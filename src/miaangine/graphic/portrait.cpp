#include "portrait.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    Portrait::Portrait(const char* dir, float scale, vector2 offset):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _master(nullptr),
        file(dir),
        scale(scale),
        offset(offset),
        color({255, 255, 255, 255})
    {}

    Portrait::Portrait(const char* dir, float scale, float ox, float oy):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _master(nullptr),
        file(dir),
        scale(scale),
        offset(vector2(ox, oy)),
        color({255, 255, 255, 255})
    {}


    Portrait::~Portrait()
    {}

    string& Portrait::name() 
    {
        return (!_master ? _ucName : _master->name);
    }

    vector2& Portrait::position() 
    {
        return (!_master ? _ucPosition : _master->position);
    }

    WorldObject* Portrait::master()
    {
        if (!_master) 
        {
            mia::DebugManager::Instance().Error("[Portrait] access denied: [master] Null reference"); //FIXME
            // return *_master; //FIXME
        }

        return _master;
    }

    void Portrait::ShiftMaster(WorldObject *master)
    {
        this->_master = master;
    }
}