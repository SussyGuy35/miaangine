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
        mia::v2f localPosition() const;
        mia::v2f globalPosition() const;
        float scale() const;

        mia::v2f& localPosition();
        mia::v2f& globalPosition();
        float& scale();

        mia::v2f GetScreenPosition();
    };
}

#endif