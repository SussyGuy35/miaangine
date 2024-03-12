#include "image.hpp"

#include "debug/debug-manager.hpp"

namespace mia
{
    Image::Image(vector2 size, vector2 offset):
        _unclaimPosition(vector2::zero()),
        size(size),
        offset(offset),
        color({255, 255, 255, 255}),
        _master(nullptr)
    {}

    Image::Image(float sx, float sy, float ox, float oy):
        _unclaimPosition(vector2::zero()),
        size(vector2(sx, sy)),
        offset(vector2(ox, oy)),
        color({255, 255, 255, 255}),
        _master(nullptr)
    {}

    Image::~Image()
    {
        delete(name);
        delete(position);
    }

    ScreenObject *Image::master()
    {
        if (!_master) 
        {
            mia::DebugManager::Instance()->Error("[Image] access denied: [master] Null reference"); //FIXME
            return nullptr;
        }

        return _master;
    }

    void Image::ShiftMaster(ScreenObject *master)
    {
        this->_master = master;
        name = &(master->name);
        position = &(master->position);
    }
}