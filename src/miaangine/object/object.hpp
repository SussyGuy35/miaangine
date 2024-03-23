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
        Object(const char* name = "untitled", Vector2<> position = Vector2<>::zero(), Vector2<> scale = Vector2<>::one());
        Object(const char* name, float px, float py, float sx = 1, float sy = 1);
        Object(Vector2<> position, Vector2<> scale = Vector2<>::one());
        Object(float px, float py, float sx = 1, float sy = 1);

        virtual ~Object();

    private: 
        // Attributes
        std::string _name;
        Vector2<> _position;
        Vector2<> _scale;

        // Components
        Sprite *_sprite;
        Body *_body;
        Collider *_collider;

    public:
        // Attributes accessing
        const char* getName() const;

        const Vector2<>& position() const;
        const Vector2<>& scale() const;

        Vector2<>& position();
        Vector2<>& scale();

        // Component methods
        Sprite& InitSprite(Vector2<> scale = Vector2<>::zero(), Vector2<> offset = Vector2<>::zero());
        Sprite& InitSprite(float sx, float sy, float ox = 0, float oy = 0);
        Body& InitBody(float mass = 1, Vector2<> initForce = Vector2<>::zero());
        Collider& InitCollider();
    };
}

#endif