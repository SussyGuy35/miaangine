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
}