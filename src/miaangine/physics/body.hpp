#ifndef _MIA_COLLIDER_HPP
#define _MIA_COLLIDER_HPP

#include <string> //FIXME
#include <memory>

#include "util/math.hpp"
#include "time/time-manager.hpp"

#include "object/world-object.hpp"

// namespace mia
// {
    class mia::Body
    {
    public:
        Body(vector2 size = vector2::zero(), vector2 offset = vector2::zero());
        Body(float sx, float sy, float ox = 0, float oy = 0);

        virtual ~Body();

    private:
        std::string _unclaimName;
        vector2 _unclaimPosition;

    public:
        vector2 size;
        vector2 offset;

        std::string *name = &_unclaimName;
        vector2 *position = &_unclaimPosition;

        WorldObject *master;

        vector2 velocity;
        bool colliding;

        void ShiftMaster(WorldObject *master);
    };
// }

#endif