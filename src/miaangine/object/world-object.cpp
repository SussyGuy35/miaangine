#include "world-object.hpp"

namespace mia
{
    void WorldObject::MakePortrait(Vector2 size, Vector2 offset)
    {
        portrait = new Portrait(size, offset);
        portrait->position = &position;
    }
    void WorldObject::MakePortrait(float sx, float sy, float ox, float oy)
    {
        portrait = new Portrait(sx, sy, ox, oy);
        portrait->position = &position;
    }

    void WorldObject::MakeCollider(Vector2 size, Vector2 offset)
    {
        collider = new Collider(size, offset);
        collider->position = &position;
    }
    void WorldObject::MakeCollider(float sx, float sy, float ox, float oy)
    {
        collider = new Collider(sx, sy, ox, oy);
        collider->position = &position;
    }
}