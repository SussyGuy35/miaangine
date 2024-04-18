#include "portrait.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Portrait::Portrait(Object *master, Sprite* sprite, v2f pivot, v2f offset, SDL_Color color):
        _master(master),
        _sprite(sprite),
        _offset(offset),
        _color(color),
        _pivot(pivot)
    {
        _master->SetPortrait(this);
    }

    Portrait::~Portrait()
    {}
#pragma endregion

#pragma region GetSet method
    const Object& Portrait::master() const
    {
        if (!_master)
        {
            // FIXME
        }

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

    Object& Portrait::master()
    {
        if (!_master)
        {
            // FIXME
        }

        return *_master;
    }
    const Sprite& Portrait::setSprite(Sprite *sprite)
    {
        _sprite = sprite;
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
        if (!newMaster)
        {
            // FIXME
        }

        _master = newMaster;
        return *_master;
    }

    rect Portrait::GetRect() const
    {
        rect res = rect();
        res.siz.x = 1.0 * sprite().siz.x / PPU;
        res.siz.y = 1.0 * sprite().siz.y / PPU;
        res.pos = master().position() + _offset - v2f(_pivot.x * res.siz.x, _pivot.y * res.siz.y);
        return res;
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