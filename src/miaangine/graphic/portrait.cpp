#include "portrait.hpp"

namespace mia
{
    Portrait::Portrait(Vector2 size, Vector2 offset):
        size(size),
        offset(offset),
        master(nullptr)
    {}

    Portrait::Portrait(float sx, float sy, float ox, float oy):
        size(Vector2(sx, sy)),
        offset(Vector2(ox, oy)),
        master(nullptr)
    {}

    void Portrait::Log()
    {
        SDL_Log(":: %f : %llu ::\n"
                "Portrait > Size(%.2f, %.2f); Offset(%.2f, %.2f)\n<>",
                Time::time, Time::stepCount,
                size.x, size.y, offset.x, offset.y);
    }
}