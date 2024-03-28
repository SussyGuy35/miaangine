#include "collider.hpp"

namespace mia
{
    #pragma region Constructor_Destructor
    Collider::Collider(Object *master, Vector2<> size, Vector2<> offset):
        _isActive(true),
        _master(master),
        _size(size),
        _offset(offset),
        _isColliding(false)
    {}
    
    Collider::~Collider()
    {}
    #pragma endregion

    #pragma region Attributes accessing
    bool Collider::isActive() const
    {
        return _isActive;
    }
    const Object& Collider::master() const
    {
        return *_master;
    }
    const Vector2<>& Collider::size() const
    {
        return _size;
    }
    const Vector2<>& Collider::offset() const
    {
        return _offset;
    }
    bool Collider::isColliding() const
    {
        return _isColliding;
    }
    bool Collider::isDynamic() const 
    {
        return _dynamic;
    }

    bool Collider::SetActive(bool newState)
    {
        return _isActive = newState;
    }
    Object& Collider::master()
    {
        return *_master;
    }
    Vector2<>& Collider::size()
    {
        return _size;
    }
    Vector2<>& Collider::offset()
    {
        return _offset;
    }
    bool Collider::SetColliding(bool newState)
    {
        return _isColliding = newState;
    }
    bool Collider::SetDynamic(bool newState)
    {
        return _dynamic = newState;
    }
    #pragma endregion

    #pragma region Properties
    float Collider::minX() const
    {
        return _master->position().x + _offset.x; 
    }
    float Collider::maxX() const
    {
        return _master->position().x + _offset.x + _size.x;
    }
    float Collider::minY() const
    {
        return _master->position().y + _offset.x; 
    }
    float Collider::maxY() const
    {
        return _master->position().y + _offset.y + _size.y;
    }
    #pragma endregion
}