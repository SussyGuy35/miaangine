#ifndef _MIA_IMAGE_HPP
#define _MIA_IMAGE_HPP

#include <SDL.h>
#include <SDL_image.h>

#include "util/math.hpp"
#include "util/string.hpp"

#include "object/screen-object.hpp"

namespace mia
{
    class Image
    {
    public:
        Image(const char* dir = "", Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero());
        Image(const char* dir, float sx, float sy, float ox, float oy);

        virtual ~Image();

    private:
        string _ucName;
        Vector2 _ucPosition;

        Vector2 _size;
        Vector2 _offset;
        string _textureDirectory;
        SDL_Texture *_texture;
        SDL_Color _color;
        ScreenObject *_master;

    public:
        string& name();
        Vector2& position();
        Vector2& size();
        Vector2& offset();
        string& textureDirectory();
        SDL_Texture* texture();
        SDL_Color& color();
        ScreenObject* master();

        const string& name() const;
        const Vector2& position() const;
        const Vector2& size() const;
        const Vector2& offset() const;
        const string& textureDirectory() const;
        const SDL_Texture* texture() const;
        const SDL_Color& color() const;
        const ScreenObject* master() const;

        void ShiftMaster(ScreenObject *master);
    };  
}

#endif