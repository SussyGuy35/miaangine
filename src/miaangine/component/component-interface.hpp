#ifndef _MIA_COMPONENT_HPP
#define _MIA_COMPONENT_HPP

#include "object/game-object.hpp"

namespace mia
{
    class IComponent
    {
    public:
        virtual GameObject* master() = 0;
        virtual bool Activate() = 0;
        virtual bool Deactivate() = 0;
        
        virtual bool operator==(const GameObject& other) = 0;
        virtual bool operator!=(const GameObject& other) = 0;
    };
}

#endif