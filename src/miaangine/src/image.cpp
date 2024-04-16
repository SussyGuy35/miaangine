#include "image.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Image::Image(UI *master, Sprite *sprite, v2f size, v2f pivot, v2f offset, SDL_Color color):
        _master(master),
        _sprite(sprite),
        _size(size),
        _pivot(pivot),
        _offset(offset),
        _color(color)
    {}

    Image::~Image()
    {}
#pragma endregion

#pragma region GetSet method
    const UI& Image::master() const
    {
        if (!_master)
        {
            // FIXME
        }

        return *_master;
    }
    const Sprite& Image::sprite() const
    {
        if (!_sprite)
        {
            // FIXME
        }

        return *_sprite;
    }
    const v2f& Image::size() const
    {
        return _size;
    }
    const v2f& Image::pivot() const
    {
        return _pivot;
    }
    const v2f& Image::offset() const
    {
        return _offset;
    }
    const SDL_Color& Image::color() const
    {
        return _color;
    }

    UI& Image::master()
    {
        if (!_master)
        {
            // FIXME
        }

        return *_master;
    }
    const Sprite& Image::setSprite(Sprite *sprite)
    {
        _sprite = sprite;
        return *_sprite;
    }
    v2f& Image::size()
    {
        return _size;
    }
    v2f& Image::pivot()
    {
        return _pivot;
    }
    v2f& Image::offset()
    {
        return _offset;
    }
    SDL_Color& Image::color()
    {
        return _color;
    }
#pragma endregion

#pragma region Public method
    UI& Image::ChangeMaster(UI *newMaster)
    {
        if (!newMaster)
        {
            // FIXME
        }

        _master = newMaster;
        return *_master;
    }

    rect Image::GetRect() const
    {
        // TODO
        // rect res = rect();
        // res.siz.x = 1.0 * sprite().siz.x / PPU;
        // res.siz.y = 1.0 * sprite().siz.y / PPU;
        // res.pos = master().position() + _offset - v2f(_pivot.x * res.siz.x, _pivot.y * res.siz.y);
        // return res;
    }
#pragma endregion

#pragma region Inherited method
    int Image::getID() const 
    {
        return _ENTITY_IMAGE;
    }
    const char* Image::ToStr() const
    {
        return "Image";
    }
#pragma endregion
}