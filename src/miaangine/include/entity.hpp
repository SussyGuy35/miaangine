#ifndef _MIA_ENTITY_HPP
#define _MIA_ENTITY_HPP

#include "common.hpp"

namespace mia
{
    enum EntityID
    {
        ENTITY_NONE = -1,
        ENTITY_ENTITY = 0,
        ENTITY_OBJECT
        //TODO
    };

    class Entity
    {
    public:
        Entity(int ID = ENTITY_ENTITY):
            _ID(ID)
        {}

        virtual ~Entity()
        {}

    protected:
        int _ID;

    public:
        virtual int getID() const
        {
            return _ID;
        }

        virtual const char* ToStr() const = 0;
    };
}

#endif