#include "transform.hpp"

namespace mia
{
#pragma region Contructor Destructor
    Transform::Transform(Object* master, v2f position, float scale):
        _position(position),
        _scale(scale)
    {}

    Transform::~Transform()
    {}
#pragma endregion

#pragma region GetSet-method
    v2f Transform::position() const 
    {
        return _position;
    }
    v2f Transform::localPosition() const
    {
        return _position - master()->transform().position();
    }
    float Transform::scale() const 
    {
        return _scale;
    }

    v2f& Transform::position()
    {
        return _position;
    }
    v2f Transform::SetLocalPosition(v2f newPosition)
    {
        return _position = master()->transform().position() + newPosition;
    }
    float& Transform::scale()
    {
        return _scale;
    }
#pragma endregion

#pragma region Inherited method
    int Transform::getID() const
    {
        return _ENTITY_TRANSFORM;
    }
    const char* Transform::ToStr() const
    {
        return string("Transform");
    }
#pragma endregion
}