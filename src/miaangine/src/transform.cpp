#include "transform.hpp"

namespace mia
{
#pragma region Contructor Destructor
    Transform::Transform(const char *name, mia::v2f position, float scale):
        Object(name),
        _localPos(position),
        _scale(scale),
        _parent(nullptr)
    {}

    Transform::~Transform()
    {}
#pragma endregion

#pragma region Get-method
    mia::v2f Transform::localPosition() const 
    {
        return _scale;
    }
    mia::v2f Transform::globalPosition() const //TODO
    {
        // return _parent
    }
    float Transform::scale() const 
    {
        return _scale;
    }
    const Transform* Transform::parent() const
    {
        return _parent;
    }
#pragma endregion

#pragma region Set-method
    mia::v2f& Transform::localPosition()
    {
        return _localPos;
    }
    mia::v2f& Transform::globalPosition()//TODO
    {

    }
    float& Transform::scale()
    {
        return _scale;
    }
    Transform* Transform::parent()
    {
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