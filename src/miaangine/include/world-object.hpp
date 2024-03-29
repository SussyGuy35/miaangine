#ifndef _MIA_WORLD_OBJECT_HPP
#define _MIA_WORLD_OBJECT_HPP

#include "object.hpp"

namespace mia
{
    class WorldObject : public Object
    {
    public:
        WorldObject(); //TODO constructor
        ~WorldObject();

    private:
        mia::v2f _localPos;
        float _scale;

    public:
        const mia::v2f localPosition() const;
        const mia::v2f globalPosition() const;
        const float 
    };
}

#endif