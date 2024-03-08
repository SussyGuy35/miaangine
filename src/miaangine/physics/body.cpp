#include "body.hpp"

#include "time/time-manager.hpp"

namespace mia
{
    Body::Body(Vector2 size, Vector2 offset):
        _unclaimName("unclaimed"),
        _unclaimPosition(Vector2::zero()),
        size(size),
        offset(offset),
        master(nullptr),
        velocity(Vector2::zero()),
        colliding(false)
    {}

    Body::Body(float sx, float sy, float ox, float oy):
        _unclaimName("unclaimed"),
        _unclaimPosition(Vector2::zero()),
        size(Vector2(sx, sy)),
        offset(Vector2(ox, oy)),
        master(nullptr),
        velocity(Vector2::zero()),
        colliding(false)
    {}

    Body::~Body()
    {

    }

    void Body::ShiftMaster(WorldObject *master)
    {
        this->master = master;
        name = &(master->name);
        position = &(master->position);
    }

    void Body::Log() //TODO
    {
        SDL_Log("%.2f - %llu | "
                "Body [%s] > Position(%.2f, %.2f); Offset(%.2f, %.2f); TotalPosition(%.2f, %2.f); Size(%.2f, %.2f); Velocity(%.2f, %.2f)",
                TimeManager::time, TimeManager::stepCount,
                name->c_str(), position->x, position->y, offset.x, offset.y, position->x + offset.x, position->y + offset.y, size.x, size.y, velocity.x, velocity.y);
    }
}