#include "portrait.hpp"

#include "renderer.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Portrait::Portrait(Sprite* sprite, v2f offset, SDL_Color color, v2f pivot):
        _sprite(sprite),
        _offset(offset),
        _color(color),
        _pivot(pivot)
    {}

    Portrait::~Portrait()
    {}
#pragma endregion

#pragma region GetSet method
    const Sprite* Portrait::sprite() const
    {
        return _sprite;
    }
    v2f Portrait::offset() const
    {
        return _offset;
    }
    SDL_Color Portrait::color() const
    {
        return _color;
    }
    v2f Portrait::pivot() const
    {
        return _pivot;
    }
    rect Portrait::getRect() const
    {
        rect res = rect();
        res.pos = _master->position() + _offset;
        res.siz.x = 1.0 * _sprite->size.x * _master->scale().x / PPU;
        res.siz.y = 1.0 * _sprite->size.y * _master->scale().y / PPU;
        return res;
    }

    Sprite* Portrait::sprite()
    {
        return _sprite;
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

#pragma region Inherited method
    int Portrait::getID() const 
    {
        return _ENTITY_PORTRAIT;
    }
    const char* Portrait::ToStr() const
    {
        return "Portrait(Component)";
    }

    bool Portrait::Init()
    {
        Renderer::Instance().RegisterPortrait(this);
    }
#pragma endregion
}