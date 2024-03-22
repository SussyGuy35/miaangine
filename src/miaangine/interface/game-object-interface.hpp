#ifndef _MIA_GAME_OBJECT_INTERFACE_HPP
#define _MIA_GAME_OBJECT_INTERFACE_HPP

#include "util/math.hpp"

namespace mia
{
    class IGameObject
    {
    public:
        virtual ~IGameObject() {}
        
        virtual const char* getName() const = 0;
    };
}

#endif