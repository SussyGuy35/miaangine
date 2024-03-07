#ifndef _MIA_COLLIDER_HPP
#define _MIA_COLLIDER_HPP

#include "util/math.hpp"
#include "core/time.hpp"

#include "object/world-object.hpp"

// namespace mia
// {
    class mia::Body
    {
    public:
        Body(Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero());
        Body(float sx, float sy, float ox = 0, float oy = 0);

        ~Body();

    private:
        Vector2 _unclaimPosition;

    public:
        Vector2 size;
        Vector2 offset;
        Vector2 *position = &_unclaimPosition;

        WorldObject *master;

        Vector2 velocity;
        bool colliding;

        virtual void Log();
    };
// }

#endif