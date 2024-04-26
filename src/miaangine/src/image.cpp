#include "image.hpp"

#include "camera.hpp"

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
    {
        _master->SetImage(this);
    }

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
        rect res = rect();
        res.siz = _size;
        res.pos.x = Camera::Instance().getScreenWidth()  * master().center().x + master().offset().x + _offset.x - _pivot.x * _size.x;
        res.pos.y = Camera::Instance().getScreenHeight() * master().center().y + master().offset().y + _offset.y - _pivot.y * _size.y;
        return res;
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