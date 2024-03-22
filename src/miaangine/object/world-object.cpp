#include "world-object.hpp"

namespace mia
{
    #pragma region Constructor_Destructor
    WorldObject::WorldObject(const char* name, Vector2<> position, Vector2<> scale):
        _name(name),
        _position(position),
        _scale(scale)
    {}

    WorldObject::~WorldObject()
    {}
    #pragma endregion

    #pragma region Attributes accessing
    const char* WorldObject::getName() const
    {
        return _name.c_str();
    }

    inline Vector2<>& WorldObject::position()
    {
        return _position;
    }
    inline Vector2<>& WorldObject::scale()
    {
        return _scale;
    }

    const Vector2<>& WorldObject::position() const
    {
        return _position;
    }
    const Vector2<>& WorldObject::scale() const
    {
        return _scale;
    }
    #pragma endregion
}