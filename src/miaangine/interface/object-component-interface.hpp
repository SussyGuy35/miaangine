#ifndef _MIA_OBJECT_COMPONENT_INTERFACE_HPP
#define _MIA_OBJECT_COMPONENT_INTERFACE_HPP

#ifndef _MIA_GAME_OBJECT_INTERFACE_HPP
#include "game-object-interface.hpp"
#endif

namespace mia
{
    typedef enum
    {
        _COMPONENT_SPRITE,
        _COMPONENT_BODY

    } Components;

    class IObjectComponent
    {
    public:
        virtual ~IObjectComponent() {}

        virtual Components getType() const = 0;
        virtual bool isActive() const = 0;
        virtual IGameObject& master() = 0;
        virtual const IGameObject& master() const = 0;

        virtual bool SetActive(bool newState) = 0;
        virtual IGameObject* ShiftMaster(IGameObject* newMaster) = 0;
    };
}

#endif