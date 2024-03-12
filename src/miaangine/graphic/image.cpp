#include "image.hpp"

namespace mia
{
    Image::Image(vector2 size, vector2 offset):
        _unclaimPosition(vector2::zero()),
        size(size),
        offset(offset),
        color({255, 255, 255, 255}),
        master(nullptr)
    {}

    Image::Image(float sx, float sy, float ox, float oy):
        _unclaimPosition(vector2::zero()),
        size(vector2(sx, sy)),
        offset(vector2(ox, oy)),
        color({255, 255, 255, 255}),
        master(nullptr)
    {}

    Image::~Image()
    {
        delete(name);
        delete(position);
    }

    void Image::ShiftMaster(ScreenObject *master)
    {
        this->master = master;
        name = &(master->name);
        position = &(master->position);
    }
}