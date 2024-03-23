#include "object.hpp"

namespace mia
{
    #pragma region Constructor_Destructor
    Object::Object(const char* name, Vector2<> position, Vector2<> scale):
        _name(name),
        _position(position),
        _scale(scale)
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
}