#include "portrait.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Portrait::Portrait(Object *master, Sprite* sprite, v2f offset, SDL_Color color, v2f pivot):
        _master(master),
        _sprite(sprite),
        _offset(offset),
        _color(color),
        _pivot(pivot)
    {}

    Portrait::~Portrait()
    {}
#pragma endregion

#pragma region GetSet method
    const Object& Portrait::master() const
    {
        return *_master;
    }
    const Sprite& Portrait::sprite() const
    {
        if (!_sprite)
        {
            // FIXME
        }

        return *_sprite;
    }
    const v2f& Portrait::offset() const
    {
        return _offset;
    }
    const SDL_Color& Portrait::color() const
    {
        return _color;
    }
    const v2f& Portrait::pivot() const
    {
        return _pivot;
    }

    Sprite& Portrait::sprite()
    {
        if (!_sprite)
        {
            // FIXME
        }

        return *_sprite;
    }
    v2f& Portrait::offset()
    {
        return _offset;
    }
    SDL_Color& Portrait::color()
    {
        return _color;
    }
    v2f& Portrait::pivot()
    {
        return _pivot;
    }
#pragma endregion

#pragma region Public method
    Object& Portrait::ChangeMaster(Object *newMaster)
    {
        _master = newMaster;
        return *_master;
    }
#pragma endregion

#pragma region Inherited method
    int Portrait::getID() const 
    {
        return _ENTITY_PORTRAIT;
    }
    const char* Portrait::ToStr() const
    {
        return "Portrait";
    }
#pragma endregion
}