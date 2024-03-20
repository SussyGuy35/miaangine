#include "portrait.hpp"

#include "core/engine-components.hpp"

namespace mia
{
    Portrait::Portrait(const char* dir, vector2 scale, vector2 offset):
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

    Portrait::Portrait(const char* dir, float sx, float sy, float ox, float oy):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _scale(vector2(sx, sy)),
        _offset(vector2(ox, oy)),
        _textureDirectory(dir),
        // _texture(nullptr),
        _master(nullptr),
        _color({255, 255, 255, 255})
    {
        _texture = sdl.LoadIMG(_textureDirectory.str());
    }

    Portrait::Portrait(vector2 scale, vector2 offset):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _scale(scale),
        _offset(offset),
        _textureDirectory(""),
        _texture(nullptr),
        _master(nullptr),
        _color({255, 255, 255, 255})
    {}

    Portrait::Portrait(float sx, float sy, float ox, float oy):
        _ucName("unclaimed"),
        _ucPosition(vector2::zero()),
        _scale(vector2(sx, sy)),
        _offset(vector2(ox, oy)),
        _textureDirectory(""),
        _texture(nullptr),
        _master(nullptr),
        _color({255, 255, 255, 255})
    {}

    Portrait::~Portrait()
    {
        SDL_DestroyTexture(_texture);
    }

    #pragma region Non-const attributes
    string& Portrait::name() 
    {
        return (!_master ? _ucName : _master->name);
    }
    vector2& Portrait::position() 
    {
        return (!_master ? _ucPosition : _master->position());
    }
    vector2& Portrait::scale()
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
            debug.Error("[Portrait(%s)] Failed to get texture {%s}; Return Null. ", name().str(), _textureDirectory.str());
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
            mia::DebugManager::Instance().Error("[Portrait(%s)] Access denied: [master] Null reference; Return Null. ", name().str());
        }

        return _master;
    }
    #pragma endregion

    #pragma region Non-const attributes
    const string& Portrait::name() const
    {
        return (!_master ? _ucName : _master->name);
    }
    const vector2& Portrait::position() const
    {
        return (!_master ? _ucPosition : _master->position());
    }
    const vector2& Portrait::scale() const
    {
        return _scale;
    }
    const vector2& Portrait::offset() const
    {
        return _offset;
    }
    const string& Portrait::textureDirectory() const
    {
        return _textureDirectory;
    }
    const SDL_Texture* Portrait::texture() const
    {
        if (!_texture)
        {
            debug.Error("[Portrait(%s)] Failed to get texture {%s}; Return Null. ", name().str(), _textureDirectory.str());
        }

        return _texture;
    }
    const SDL_Color& Portrait::color() const
    {
        return _color;
    }
    const WorldObject* Portrait::master() const
    {
        if (!_master) 
        {
            mia::DebugManager::Instance().Error("[Portrait(%s)] Access denied: [master] Null reference; Return Null. ", name().str());
        }

        return _master;
    }
    #pragma endregion

    void Portrait::ShiftMaster(WorldObject *master)
    {
        this->_master = master;
    }
}