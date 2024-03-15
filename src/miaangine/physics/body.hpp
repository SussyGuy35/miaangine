#ifndef _MIA_COLLIDER_HPP
#define _MIA_COLLIDER_HPP

#include <memory>

#include "util/math.hpp"

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
        string _ucName;
        vector2 _ucPosition;

        WorldObject *_master;

    public:
        vector2 size;
        vector2 offset;

        string& name() ;
        vector2& position() ;

        WorldObject* master();

        vector2 velocity;
        bool colliding;

        void ShiftMaster(WorldObject *master);
    };
// }

#endif