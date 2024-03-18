#include "image.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    Image::Image(const char* dir, float scale, vector2 offset):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _scale(scale),
        _offset(offset),
        _textureDirectory(dir),
        // _texture(nullptr),
        _master(nullptr),
        _color({255, 255, 255, 255})
    {
        _texture = sdl.LoadIMG(_textureDirectory.str());
    }

    Image::Image(const char* dir, float scale, float ox, float oy):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _scale(scale),
        _offset(vector2(ox, oy)),
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

    string& Image::name() 
    {
        return (!_master ? _ucName : _master->name);
    }
    vector2& Image::position() 
    {
        return (!_master ? _ucPosition : _master->position);
    }
    float& Image::scale()
    {
        return _scale;
    }
    vector2& Image::offset()
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
            debug.Error("[Image(%s)] Failed to get texture {%s}", name(), _textureDirectory.str()); //FIXME
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
            mia::DebugManager::Instance().Error("[Image] access denied: [master] Null reference"); //FIXME
        }

        return _master;
    }

    void Image::ShiftMaster(ScreenObject *master)
    {
        this->_master = master;
    }
}