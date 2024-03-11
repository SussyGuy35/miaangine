#include "body.hpp"

#include "time/time-manager.hpp"

namespace mia
{
    Body::Body(vector2 size, vector2 offset):
        _unclaimName("unclaimed"),
        _unclaimPosition(vector2::zero()),
        size(size),
        offset(offset),
        master(nullptr),
        velocity(vector2::zero()),
        colliding(false)
    {}

    Body::Body(float sx, float sy, float ox, float oy):
        _unclaimName("unclaimed"),
        _unclaimPosition(vector2::zero()),
        size(vector2(sx, sy)),
        offset(vector2(ox, oy)),
        master(nullptr),
        velocity(vector2::zero()),
        colliding(false)
    {}

    Body::~Body()
    {
        delete(name);
        delete(position);
    }

    void Body::ShiftMaster(WorldObject *master)
    {
        this->master = master;
        name = &(master->name);
        position = &(master->position);
    }
}