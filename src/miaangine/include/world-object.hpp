#ifndef _MIA_WORLD_OBJECT_HPP
#define _MIA_WORLD_OBJECT_HPP

#include "transform.hpp"

namespace mia
{
    class WorldObject : public Transform
    {
    public:
        WorldObject(const char *name = "unnamed", mia::v2f position = mia::v2f::zero(), float scale = 1, Transform* parent = nullptr);
        ~WorldObject();

    public:

    public:
        int getID() const override;
        const char* ToStr() const override;
    };
}

#endif