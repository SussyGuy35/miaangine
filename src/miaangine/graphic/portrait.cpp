#include "portrait.hpp"

namespace mia
{
    Portrait::Portrait(Vector2 size, Vector2 offset, SDL_Color color):
        size(size),
        offset(offset),
        color(color),
        master(nullptr)
    {}

    Portrait::Portrait(float sx, float sy, float ox, float oy, SDL_Color color):
        size(Vector2(sx, sy)),
        offset(Vector2(ox, oy)),
        color(color),
        master(nullptr)
    {}

    void Portrait::Log() //TODO
    {
        SDL_Log("%.2f - %llu | "
                "Portrait > Size(%.2f, %.2f); Offset(%.2f, %.2f)",
                Time::time, Time::stepCount,
                size.x, size.y, offset.x, offset.y);
    }
}