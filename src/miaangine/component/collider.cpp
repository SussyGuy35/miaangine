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
    const Collider::Object& master() const
    {
        return *_master;
    }
    const Collider::Vector2<>& size() const
    {
        return _size;
    }
    const Collider::Vector2<>& offset() const
    {
        return _offset;
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
    #pragma endregion

    #pragma region Properties
    Vector2<> Collider::minX() const
    {
        return _master->position().x; 
    }
    Vector2<> Collider::maxX() const
    {
        return _master->position().x + _offset.x;
    }
    Vector2<> Collider::minY() const
    {
        return _master->position().y; 
    }
    Vector2<> Collider::maxY() const
    {
        return _master->position().y + _offset.y;
    }
    bool Collider::isColliding() const
    {
        return _isColliding;
    }
    #pragma endregion
}