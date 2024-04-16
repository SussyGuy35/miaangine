#ifndef _MIA_ENTITY_HPP
#define _MIA_ENTITY_HPP

#include "common.hpp"

namespace mia
{
    enum EntityID //TODO remove this
    {
        _ENTITY_NONE,
        _ENTITY_OBJECT,
        _ENTITY_TRANSFORM,
        _ENTITY_WORLDOBJECT,
        _ENTITY_COMPONENT,
        _ENTITY_PORTRAIT,
        _ENTITY_BODY,
        _ENTITY_UI,
        _ENTITY_IMAGE
        //TODO
    };

    class Entity
    {
    public:
        Entity() {}
        virtual ~Entity() {}

        virtual int getID() const = 0;
        virtual const char* ToStr() const = 0;
    };
}

#endif