#include "portrait.hpp"

#include "renderer.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Portrait::Portrait(Sprite* sprite, mia::v2f offset, SDL_Color color):
        _sprite(sprite),
        _offset(offset),
        _color(color)
    {}

    Portrait::~Portrait()
    {}
#pragma endregion

#pragma region GetSet method
    const Sprite* Portrait::sprite() const
    {
        return _sprite;
    }
    mia::v2f Portrait::offset() const
    {
        return _offset;
    }
    SDL_Color Portrait::color() const
    {
        return _color;
    }

    Sprite* Portrait::sprite()
    {
        return _sprite;
    }
    mia::v2f& Portrait::offset()
    {
        return _offset;
    }
    SDL_Color& Portrait::color()
    {
        return _color;
    }
#pragma endregion

#pragma region Inherited method
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