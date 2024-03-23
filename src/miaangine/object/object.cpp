#include "object.hpp"

#include "core/engine-components.hpp"

#include "component/sprite.hpp"
#include "component/body.hpp"
#include "component/collider.hpp"

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
    Object::Object(const char* name, float px, float py, float sx, float sy):
        _name(name),
        _position(Vector2<>(px, py)),
        _scale(Vector2<>(sx, sy)),
        _sprite(nullptr),
        _body(nullptr),
        _collider(nullptr)
    {}
    Object::Object(Vector2<> position, Vector2<> scale):
        _name("untitled"),
        _position(position),
        _scale(scale),
        _sprite(nullptr),
        _body(nullptr),
        _collider(nullptr)
    {}
    Object::Object(float px, float py, float sx, float sy):
        _name("untitled"),
        _position(Vector2<>(px, py)),
        _scale(Vector2<>(sx, sy)),
        _sprite(nullptr),
        _body(nullptr),
        _collider(nullptr)
    {}

    Object::~Object()
    {
        delete _sprite;
        delete _body;
        delete _collider;
    }
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
    Sprite& Object::sprite()
    {
        return *_sprite;
    }
    Body& Object::body()
    {
        return *_body;
    }
    Collider& Object::collider()
    {
        return *_collider;
    }
    #pragma endregion

    #pragma region Component methods 
    Sprite& Object::InitSprite(Vector2<> scale, Vector2<> offset)
    {
        _sprite = new Sprite(this, scale, offset);

        render().RegisterSprite(_sprite);

        return *_sprite;
    }
    Sprite& Object::InitSprite(float sx, float sy, float ox, float oy)
    {
        _sprite = new Sprite(this, Vector2<>(sx, sy), Vector2<>(ox, oy));

        render().RegisterSprite(_sprite);

        return *_sprite;
    }
    Body& Object::InitBody(float mass, Vector2<> initForce)
    {
        _body = new Body(this, mass, initForce);// TODO Add registeration
    }
    Collider& Object::InitCollider()
    {

    }
    #pragma endregion
}