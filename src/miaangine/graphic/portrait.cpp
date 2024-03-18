#include "portrait.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    Portrait::Portrait(const char* dir, float scale, vector2 offset):
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

    Portrait::Portrait(const char* dir, float scale, float ox, float oy):
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

    Portrait::~Portrait()
    {
        SDL_DestroyTexture(_texture);
    }

    string& Portrait::name() 
    {
        return (!_master ? _ucName : _master->name);
    }
    vector2& Portrait::position() 
    {
        return (!_master ? _ucPosition : _master->position());
    }
    float& Portrait::scale()
    {
        return _scale;
    }
    vector2& Portrait::offset()
    {
        return _offset;
    }
    string& Portrait::textureDirectory()
    {
        return _textureDirectory;
    }
    SDL_Texture* Portrait::texture()
    {
        if (!_texture)
        {
            debug.Error("[Portrait(%s)] Failed to get texture {%s}", name(), _textureDirectory.str()); //FIXME
        }

        return _texture;
    }
    SDL_Color& Portrait::color()
    {
        return _color;
    }

    WorldObject* Portrait::master()
    {
        if (!_master) 
        {
            mia::DebugManager::Instance().Error("[Portrait] access denied: [master] Null reference"); //FIXME
        }

        return _master;
    }

    void Portrait::ShiftMaster(WorldObject *master)
    {
        this->_master = master;
    }
}