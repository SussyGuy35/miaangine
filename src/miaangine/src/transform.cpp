#include "transform.hpp"

namespace mia
{
#pragma region Contructor Destructor
    Transform::Transform(const char *name, mia::v2f position, float scale, Transform* parent):
        Object(name),
        _position(position),
        _scale(scale),
        _parent(parent)
    {}

    Transform::~Transform()
    {}
#pragma endregion

#pragma region Get-method
    mia::v2f Transform::position() const 
    {
        return _position;
    }
    mia::v2f Transform::localPosition() const
    {
        return _position - _parent->_position;
    }
    float Transform::scale() const 
    {
        return _scale;
    }
    const Transform* Transform::parent() const
    {
        // TODO safety
        return _parent;
    }
#pragma endregion

#pragma region Set-method
    mia::v2f& Transform::position()
    {
        return _position;
    }
    mia::v2f Transform::SetLocalPosition(mia::v2f newPosition)
    {
        return _position = _parent->_position + newPosition;
    }
    float& Transform::scale()
    {
        return _scale;
    }
    Transform* Transform::parent()
    {
        // TODO safety
        return _parent;
    }
#pragma endregion

#pragma region Public method
#pragma endregion

#pragma region Inherited method
    const char* Transform::ToStr() const
    {
        return mia::string("Transform");
    }
#pragma endregion
}