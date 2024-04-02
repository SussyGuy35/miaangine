#include "transform.hpp"

namespace mia
{
#pragma region Contructor Destructor
    Transform::Transform(const char *name, mia::v2f position, float scale, Transform* parent):
        Object(name, this),
        _position(position),
        _scale(scale),
        _parent(parent)
    {}

    Transform::~Transform()
    {}
#pragma endregion

#pragma region GetSet-method
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

#pragma region Inherited method
    int Transform::getID() const
    {
        return _ENTITY_TRANSFORM;
    }
    const char* Transform::ToStr() const
    {
        return mia::string("Transform");
    }
#pragma endregion
}