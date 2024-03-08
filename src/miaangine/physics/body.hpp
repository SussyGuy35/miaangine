#ifndef _MIA_COLLIDER_HPP
#define _MIA_COLLIDER_HPP

#include <string>

#include "util/math.hpp"
#include "time/time.hpp"

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
        std::string _unclaimName;
        Vector2 _unclaimPosition;

    public:
        Vector2 size;
        Vector2 offset;

        std::string *name = &_unclaimName;
        Vector2 *position = &_unclaimPosition;

        WorldObject *master;

        Vector2 velocity;
        bool colliding;

        void ShiftMaster(WorldObject *master);
        virtual void Log();
    };
// }

#endif