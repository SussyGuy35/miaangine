#include "sprite.hpp"

namespace mia
{
    #pragma region Constructor_Destructor
    Sprite::Sprite(Vector2<> scale, Vector2<> offset):
        _isActive(true),
        _master(nullptr),
        _scale(scale),
        _offset(offset),
        _textureDirectory(""),
        _color({255, 255, 255, 255})
    {}

    Sprite::Sprite(float sx, float sy, float ox, float oy):
        _isActive(true),
        _master(nullptr),
        _scale(Vector2<>(sx, sy)),
        _offset(Vector2<>(ox, oy)),
        _textureDirectory(""),
        _color({255, 255, 255, 255})
    {}

    Sprite::~Sprite()
    {}
    #pragma endregion

    #pragma region Attributes accessing
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

    Vector2<>& Sprite::scale()
    {
        return _scale;
    }
    Vector2<>& Sprite::offset()
    {
        return _offset;
    }
    #pragma endregion

    #pragma region Abstract methods
    Components Sprite::getType() const 
    { 
        return _COMPONENT_SPRITE; 
    }
    bool Sprite::isActive() const 
    { 
        return _isActive; 
    }
    bool Sprite::SetActive(bool newState) 
    { 
        return _isActive = newState; 
    }
    IGameObject& Sprite::master() 
    { 
        return *_master; 
    } 
    const IGameObject& Sprite::master() const 
    { 
        return *_master; 
    }
    #pragma endregion
}