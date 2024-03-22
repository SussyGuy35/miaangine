#ifndef _MIA_GAME_OBJECT_INTERFACE_HPP
#define _MIA_GAME_OBJECT_INTERFACE_HPP

#include "util/math.hpp"

namespace mia
{
    struct Transform
    {
        Vector2<> position;
        float scale;
    }

    class IGameObject
    {
    public:
        IGameObject();
        virtual ~IGameObject();

        virtual const char* getName() const = 0;

        virtual Vector2<>& position() = 0;
        virtual float& scale() = 0;
        virtual const Vector2<>& getPosition() const = 0;
        virtual const float& getScale() const = 0;
    };
}

#endif