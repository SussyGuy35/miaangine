#ifndef _MIA_GAME_OBJECT_HPP
#define _MIA_GAME_OBJECT_HPP

#include <string>

#include "event/event-listener-interface.hpp"

namespace mia
{
    class GameObject : public IEventListener
    {
    public:
        GameObject(const char* name = "object"):
            name(name)
        {}

        virtual ~GameObject() {}

        std::string name;
    };
}

#endif