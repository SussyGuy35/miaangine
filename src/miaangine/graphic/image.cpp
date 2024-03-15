#include "image.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    Image::Image(vector2 size, vector2 offset):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        size(size),
        offset(offset),
        color({255, 255, 255, 255}),
        _master(nullptr)
    {}

    Image::Image(float sx, float sy, float ox, float oy):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        size(vector2(sx, sy)),
        offset(vector2(ox, oy)),
        color({255, 255, 255, 255}),
        _master(nullptr)
    {}

    Image::~Image()
    {}

    const string& Image::name() const
    {
        return (!_master ? _ucName : _master->name);
    }

    const vector2& Image::position() const
    {
        return (!_master ? _ucPosition : _master->position);
    }

    ScreenObject* Image::master()
    {
        if (!_master) 
        {
            mia::DebugManager::Instance().Error("[Image] access denied: [master] Null reference"); //FIXME
            // return *_master; //FIXME
        }

        return _master;
    }

    void Image::ShiftMaster(ScreenObject *master)
    {
        this->_master = master;
    }
}