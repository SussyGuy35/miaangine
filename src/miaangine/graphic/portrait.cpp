#include "portrait.hpp"

namespace mia
{
    Portrait::Portrait(vector2 size, vector2 offset):
        _unclaimPosition(vector2::zero()),
        size(size),
        offset(offset),
        color({255, 255, 255, 255}),
        master(nullptr)
    {}

    Portrait::Portrait(float sx, float sy, float ox, float oy):
        _unclaimPosition(vector2::zero()),
        size(vector2(sx, sy)),
        offset(vector2(ox, oy)),
        color({255, 255, 255, 255}),
        master(nullptr)
    {}

    Portrait::~Portrait()
    {
        delete(name);
        delete(position);
    }

    void Portrait::ShiftMaster(WorldObject *master)
    {
        this->master = master;
        name = &(master->name);
        position = &(master->position);
    }
}