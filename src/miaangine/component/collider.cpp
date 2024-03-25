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
    bool Collider::isColliding() const
    {
        return _isColliding;
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
    bool Collider::SetColiding(bool newState)
    {
        return _isColliding = newState;
    }
    #pragma endregion

    #pragma region Properties
    float Collider::minX() const
    {
        return _master->position().x; 
    }
    float Collider::maxX() const
    {
        return _master->position().x + _offset.x;
    }
    float Collider::minY() const
    {
        return _master->position().y; 
    }
    float Collider::maxY() const
    {
        return _master->position().y + _offset.y;
    }
    #pragma endregion
}