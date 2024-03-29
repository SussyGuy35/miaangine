#ifndef _MIA_ENTITY_HPP
#define _MIA_ENTITY_HPP

#include "util/util.hpp"

namespace mia
{
    class Entity
    {
    public:
        Entity(int ID = EntityID::None):
            _ID(ID)
        {}

        ~Entity()
        {}

    protected:
        int _ID;

    public:
        virtual int getID() const
        {
            return _ID;
        }

        virtual mia::string ToStr() = 0;
    };

    enum EntityID
    {
        None = -1,
        Entity = 0
        //TODO
    };
}

#endif