#include "sprite.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    #pragma region Constructor_Destructor
    Sprite::Sprite(Object *master, Vector2<> scale, Vector2<> offset):
        _isActive(true),
        _master(master),
        _scale(scale),
        _offset(offset),
        _textureDirectory(""),
        _color({255, 255, 255, 255}),
        _hasTexture(false)
    {}

    Sprite::~Sprite()
    {
        SDL_DestroyTexture(_texture);
    }
    #pragma endregion

    #pragma region Attributes accessing
    bool Sprite::isActive() const 
    { 
        return _isActive; 
    }
    const Object& Sprite::master() const 
    { 
        return *_master; 
    }
    const Vector2<>& Sprite::scale() const 
    {
        return _scale;
    }
    const Vector2<>& Sprite::offset() const 
    {
        return _offset;
    }
    const char* Sprite::getTextureDir() const 
    {
        return _textureDirectory.c_str();
    }
    const SDL_Color& Sprite::color() const
    {
        return _color;
    }
    bool Sprite::hasTexture() const
    {
        return _hasTexture;
    }

    bool Sprite::SetActive(bool newState) 
    { 
        return _isActive = newState; 
    }
    Object& Sprite::master() 
    { 
        return *_master; 
    }
    Vector2<>& Sprite::scale()
    {
        return _scale;
    }
    Vector2<>& Sprite::offset()
    {
        return _offset;
    }
    SDL_Texture* Sprite::texture()
    {
        return _texture;
    }
    SDL_Color& Sprite::color()
    {
        return _color;
    }
    #pragma endregion

    #pragma region Methods
    SDL_Texture* Sprite::Load(const char* dir)
    {
        _textureDirectory = dir;

        _texture = IMG_LoadTexture(generic().renderer, dir);

        _hasTexture = true;
    }
    #pragma endregion
}