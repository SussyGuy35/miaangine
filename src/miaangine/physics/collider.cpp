#include "collider.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    Collider::Collider(vector2 size, vector2 offset):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _size(size),
        _offset(offset),
        _body(nullptr),
        _master(nullptr)
    {}
    Collider::Collider(float sx, float sy, float ox, float oy):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _size(vector2(sx, sy)),
        _offset(vector2(ox, oy)),
        _body(nullptr),
        _master(nullptr)
    {}

    Collider::~Collider()
    {}

    #pragma region Non-const attributes
    string& Collider::name()
    {
        return (!_master ? _ucName : _master->name);
    }
    vector2& Collider::position()
    {
        return (!_master ? _ucPosition : _master->position());
    }
    vector2& Collider::size()
    {
        return _size;
    }
    vector2& Collider::offset()
    {
        return _offset;
    }
    Body* Collider::body()
    {
        if (!_body) 
        {
            mia::debug.Error("[Collider(%s)] access denied: [body] Null reference; Return null. ", name().str());
        }

        return _body;
    }
    WorldObject* Collider::master()
    {
        if (!_master) 
        {
            mia::debug.Error("[Collider(%s)] access denied: [master] Null reference;  Return null. ", name().str());
        }

        return _master;
    }
    #pragma endregion

    #pragma region Const attributes
    const string& Collider::name() const
    {
        return (!_master ? _ucName : _master->name);
    }
    const vector2& Collider::position() const
    {
        return (!_master ? _ucPosition : _master->position());
    }
    const vector2& Collider::size() const
    {
        return _size;
    }
    const vector2& Collider::offset() const
    {
        return _offset;
    }
    const Body* Collider::body() const
    {
        if (!_body) 
        {
            mia::debug.Error("[Collider(%s)] access denied: [body] Null reference; Return null. ", name().str());
        }

        return _body;
    }
    const WorldObject* Collider::master() const
    {
        if (!_master) 
        {
            mia::debug.Error("[Collider(%s)] access denied: [master] Null reference;  Return null. ", name().str());
        }

        return _master;
    }
    #pragma endregion

    bool Collider::CheckColliding(Collider *other)
    {
        float aMinX = position().x + _offset.x;
        float aMinY = position().y + _offset.y;
        float aMaxX = position().x + _offset.x + _size.x;
        float aMaxY = position().y + _offset.y + _size.y;

        float bMinX = other->position().x + other->_offset.x;
        float bMinY = other->position().y + other->_offset.y;
        float bMaxX = other->position().x + other->_offset.x + other->_size.x;
        float bMaxY = other->position().y + other->_offset.y + other->_size.y;

        return (
            aMinX <= bMaxX &&
            aMaxX >= bMinX &&
            aMinY <= bMaxY &&
            aMaxY >= bMinY
        );
    }

    void Collider::ShiftBody(Body *body)
    {
        this->_body = body;
    }
    void Collider::ShiftMaster(WorldObject *master)
    {
        this->_master = master;
    }
}