#include "image.hpp"

namespace mia
{
    Image::Image(Vector2 size, Vector2 offset, SDL_Color color):
        _unclaimPosition(Vector2::zero()),
        size(size),
        offset(offset),
        color(color),
        master(nullptr)
    {}

    Image::Image(float sx, float sy, float ox, float oy, SDL_Color color):
        _unclaimPosition(Vector2::zero()),
        size(Vector2(sx, sy)),
        offset(Vector2(ox, oy)),
        color(color),
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