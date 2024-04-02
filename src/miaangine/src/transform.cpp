#include "transform.hpp"

namespace mia
{
#pragma region Contructor Destructor
    Transform::Transform(v2f position, float scale, Transform *parent, Object *master):
        _position(position),
        _scale(scale),
        _parent(parent),
        _master(master)
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
    const Transform& Transform::parent() const
    {
        return *_parent;
    }
    const Object* Transform::master() const
    {
        return _master;
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
    Transform& Transform::parent()
    {
        return *_parent;
    }
    Object* Transform::master()
    {
        return _master;
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