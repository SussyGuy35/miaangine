#ifndef _MIA_OBJECT_HPP
#define _MIA_OBJECT_HPP

#include <string>
#include "util/math.hpp"

namespace mia 
{
    // Forward decleration
    class Sprite;
    class Body;
    class Collider;

    class Object
    {
    public:
        Object(const char* name = "object", Vector2<> position = Vector2<>::zero(), Vector2<> scale = Vector2<>::zero());

        virtual ~Object();

    private: 
        // Attributes
        std::string _name;
        Vector2<> _position;
        Vector2<> _scale;

        // Components
        Sprite _sprite;
        Body _body;
        Collider _collider;

    public:
        // Attributes accessing
        const char* getName() const;

        const Vector2<>& position() const;
        const Vector2<>& scale() const;

        Vector2<>& position();
        Vector2<>& scale();

        // Methods
        Sprite& InitSprite();
        Body& InitBody();
        Collider& InitCollider();
    };
}

#endif