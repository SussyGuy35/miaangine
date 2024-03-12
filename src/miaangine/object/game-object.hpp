#ifndef _MIA_GAME_OBJECT_HPP
#define _MIA_GAME_OBJECT_HPP

#include "event/event-listener-interface.hpp"

#include "util/string.hpp"

namespace mia
{
    class GameObject : public IEventListener
    {
    public:
        GameObject(const char* name = "object"):
            name(name)
        {}

        virtual ~GameObject() {}

        string name;
    };
}

#endif