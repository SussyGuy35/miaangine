#include "portrait.hpp"

#include "time/time-manager.hpp"

namespace mia
{
    Portrait::Portrait(Vector2 size, Vector2 offset, SDL_Color color):
        _unclaimPosition(Vector2::zero()),
        size(size),
        offset(offset),
        color(color),
        master(nullptr)
    {}

    Portrait::Portrait(float sx, float sy, float ox, float oy, SDL_Color color):
        _unclaimPosition(Vector2::zero()),
        size(Vector2(sx, sy)),
        offset(Vector2(ox, oy)),
        color(color),
        master(nullptr)
    {}

    Portrait::~Portrait()
    {

    }

    void Portrait::ShiftMaster(WorldObject *master)
    {
        this->master = master;
        name = &(master->name);
        position = &(master->position);
    }
}