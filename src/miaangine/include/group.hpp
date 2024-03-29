#ifndef _MIA_GROUP_HPP
#define _MIA_GROUP_HPP

#include "common.hpp"
#include "entity.hpp"

namespace mia
{
    class Group : public mia::Entity
    {
    public:
        std::vector<mia::Entity*> members;

        Group();
        ~Group();

        // mia::Entity* operator+=(mia::Entity& ett);
        mia::Entity* operator+=(mia::Entity* ett);
        mia::Entity* Add(mia::Entity* ett);
    };
}

#endif