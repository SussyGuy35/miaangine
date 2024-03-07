#include "body.hpp"

namespace mia
{
    Body::Body(Vector2 size, Vector2 offset):
        size(size),
        offset(offset),
        position(new Vector2()),
        master(nullptr),
        velocity(Vector2::zero()),
        colliding(false)
    {}

    Body::Body(float sx, float sy, float ox, float oy):
        size(Vector2(sx, sy)),
        offset(Vector2(ox, oy)),
        position(new Vector2()),
        master(nullptr),
        velocity(Vector2::zero()),
        colliding(false)
    {}

    Body::~Body()
    {
        delete(position);
    }

    void Body::Log() //TODO
    {
        SDL_Log("%.2f - %llu | "
                "Body > Size(%.2f, %.2f); Offset(%.2f, %.2f); Velocity(%.2f, %.2f); Colliding(%d)",
                Time::time, Time::stepCount,
                size.x, size.y, offset.x, offset.y, velocity.x, velocity.y, colliding);
    }
}