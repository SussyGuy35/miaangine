#include "portrait.hpp"

namespace mia
{
    Portrait::Portrait(Vector2 size, Vector2 offset, SDL_Color color):
        size(size),
        offset(offset),
        position(new Vector2()),
        color(color),
        master(nullptr)
    {}

    Portrait::Portrait(float sx, float sy, float ox, float oy, SDL_Color color):
        size(Vector2(sx, sy)),
        offset(Vector2(ox, oy)),
        position(new Vector2()),
        color(color),
        master(nullptr)
    {}

    Portrait::~Portrait()
    {
        delete(position);
    }

    void Portrait::Log() //TODO
    {
        SDL_Log("%.2f - %llu | "
                "Portrait > Position(%.2f, %.2f); Offset(%.2f, %.2f); TotalPosition(%.2f, %2.f); Size(%.2f, %.2f); Color(%d, %d, %d, %d)",
                Time::time, Time::stepCount,
                position->x, position->y, offset.x, offset.y, position->x + offset.x, position->y + offset.y, size.x, size.y, color.r, color.b, color.g, color.a);
    }
}