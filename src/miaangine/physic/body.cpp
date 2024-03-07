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
                "Body > Position(%.2f, %.2f); Offset(%.2f, %.2f); TotalPosition(%.2f, %2.f); Size(%.2f, %.2f); Velocity(%.2f, %.2f)",
                Time::time, Time::stepCount,
                position->x, position->y, offset.x, offset.y, position->x + offset.x, position->y + offset.y, size.x, size.y, velocity.x, velocity.y);
    }
}