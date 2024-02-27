#include "body.hpp"

namespace mia
{
    Body::Body(Vector2 size, Vector2 offset):
        size(size),
        offset(offset),
        master(nullptr),
        colliding(false)
    {}

    Body::Body(float sx, float sy, float ox, float oy):
        size(Vector2(sx, sy)),
        offset(Vector2(ox, oy)),
        master(nullptr),
        colliding(false)
    {}
}