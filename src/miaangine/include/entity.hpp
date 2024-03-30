#ifndef _MIA_ENTITY_HPP
#define _MIA_ENTITY_HPP

#include "common.hpp"

namespace mia
{
    enum EntityID
    {
        _ENTITY_NONE = -1,
        _ENTITY_ENTITY = 0,
        _ENTITY_OBJECT
        //TODO
    };

    class Entity
    {
    public:
        Entity(int ID = _ENTITY_ENTITY):
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