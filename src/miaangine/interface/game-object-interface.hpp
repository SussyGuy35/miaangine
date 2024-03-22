#ifndef _MIA_GAME_OBJECT_INTERFACE_HPP
#define _MIA_GAME_OBJECT_INTERFACE_HPP

namespace mia
{
    class IObjectComponent;

    class IGameObject
    {
    public:
        virtual ~IGameObject() {}
        
        virtual const char* getName() const = 0;
    };
}

#endif