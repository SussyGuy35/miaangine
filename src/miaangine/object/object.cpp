#include "object.hpp"

#include "component/sprite.hpp"
#include "component/body.hpp"

namespace mia
{
    #pragma region Constructor_Destructor
    Object::Object(const char* name, Vector2<> position, Vector2<> scale):
        _name(name),
        _position(position),
        _scale(scale),
        _sprite(nullptr),
        _body(nullptr),
        _collider(nullptr)
    {}

    Object::~Object()
    {}
    #pragma endregion

    #pragma region Attributes accessing
    const char* Object::getName() const
    {
        return _name.c_str();
    }

    const Vector2<>& Object::position() const
    {
        return _position;
    }
    const Vector2<>& Object::scale() const
    {
        return _scale;
    }

    Vector2<>& Object::position()
    {
        return _position;
    }
    Vector2<>& Object::scale()
    {
        return _scale;
    }
    #pragma endregion

    #pragma region Component methods // TODO Add registeration
    Sprite& Object::InitSprite(Vector2<> scale, Vector2<> offset)
    {
        _sprite = new Sprite(scale, offset);
    }
    Sprite& Object::InitSprite(float sx, float sy, float ox, float oy)
    {
        _sprite = new Sprite(sx, sy, ox, oy);
    }
    Body& Object::InitBody(float mass, Vector2<> initForce)
    {
        _body = new Body(mass, initForce);
    }
    Collider& Object::InitCollider()
    {

    }
    #pragma endregion
}