#include "image.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    Image::Image(const char* dir, Vector2 size, Vector2 offset):
        _ucName("unclaimed"),
        _ucPosition(Vector2::zero()),
        _size(size),
        _offset(offset),
        _textureDirectory(dir),
        // _texture(nullptr),
        _master(nullptr),
        _color({255, 255, 255, 255})
    {
        _texture = sdl.LoadIMG(_textureDirectory.str());
    }

    Image::Image(const char* dir, float sx, float sy, float ox, float oy):
        _ucName("unclaimed"),
        _ucPosition(Vector2::zero()),
        _size(Vector2(sx, sy)),
        _offset(Vector2(ox, oy)),
        _textureDirectory(dir),
        // _texture(nullptr),
        _master(nullptr),
        _color({255, 255, 255, 255})
    {
        _texture = sdl.LoadIMG(_textureDirectory.str());
    }

    Image::~Image()
    {
        SDL_DestroyTexture(_texture);
    }

    #pragma region Non-const attributes
    string& Image::name() 
    {
        return (!_master ? _ucName : _master->name);
    }
    Vector2& Image::position() 
    {
        return (!_master ? _ucPosition : _master->position());
    }
    Vector2& Image::size()
    {
        return _size;
    }
    Vector2& Image::offset()
    {
        return _offset;
    }
    string& Image::textureDirectory()
    {
        return _textureDirectory;
    }
    SDL_Texture* Image::texture()
    {
        if (!_texture)
        {
            debug.Error("[Image(%s)] Failed to get texture {%s}; Return Null. ", name().str(), _textureDirectory.str());
        }

        return _texture;
    }
    SDL_Color& Image::color()
    {
        return _color;
    }
    ScreenObject* Image::master()
    {
        if (!_master) 
        {
            mia::DebugManager::Instance().Error("[Image(%s)] Access denied: [master] Null reference; Return Null. ", name().str());
        }

        return _master;
    }
    #pragma endregion
    
    #pragma region Const attributes
    const string& Image::name() const
    {
        return (!_master ? _ucName : _master->name);
    }
    const Vector2& Image::position() const
    {
        return (!_master ? _ucPosition : _master->position());
    }
    const Vector2& Image::size() const
    {
        return _size;
    }
    const Vector2& Image::offset() const
    {
        return _offset;
    }
    const string& Image::textureDirectory() const
    {
        return _textureDirectory;
    }
    const SDL_Texture* Image::texture() const
    {
        if (!_texture)
        {
            debug.Error("[Image(%s)] Failed to get texture {%s}; Return Null. ", name().str(), _textureDirectory.str());
        }

        return _texture;
    }
    const SDL_Color& Image::color() const
    {
        return _color;
    }
    const ScreenObject* Image::master() const
    {
        if (!_master) 
        {
            mia::DebugManager::Instance().Error("[Image(%s)] Access denied: [master] Null reference; Return Null. ", name().str());
        }

        return _master;
    }
    #pragma endregion

    void Image::ShiftMaster(ScreenObject *master)
    {
        this->_master = master;
    }
}