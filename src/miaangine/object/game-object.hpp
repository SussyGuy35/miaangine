#ifndef _MIA_GAME_OBJECT_HPP
#define _MIA_GAME_OBJECT_HPP

#include "interface/game-object-interface.hpp"
#include "event/event-listener-interface.hpp"

#include <string>

namespace mia
{
    class GameObject : public IGameObject, public IEventListener
    {
    public:
        GameObject(const char* name = "untitled"):
            name(name)
        {}

        virtual ~GameObject() {}

        std::string name;

        const char* getName() const override
        {
            return name.c_str();
        }
    };
}

#endif