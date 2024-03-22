#ifndef _MIA_WORLD_OBJECT_HPP
#define _MIA_WORLD_OBJECT_HPP

#include "interface/game-object-interface.hpp"

#include <string>
#include "util/math.hpp"

namespace mia 
{
    class WorldObject : public IGameObject
    {
    public:
        WorldObject(const char* name = "object", Vector2<> position = Vector2<>::zero(), Vector2<> scale = Vector2<>::zero());

        virtual ~WorldObject();

    // Attributes
    private: 
        std::string _name;
        Vector2<> _position;
        Vector2<> _scale;

    public:
        // Attributes accessing
        const char* getName() const;

        const Vector2<>& position() const;
        const Vector2<>& scale() const;

        Vector2<>& position();
        Vector2<>& scale();
    };
}

#endif