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
        Image(const char* dir = "", vector2 size = vector2::zero(), vector2 offset = vector2::zero());
        Image(const char* dir, float sx, float sy, float ox = 0, float oy = 0);

        virtual ~Image();

    private:
        string _ucName;
        vector2 _ucPosition;

        vector2 _size;
        vector2 _offset;
        string _textureDirectory;
        SDL_Texture *_texture;
        SDL_Color _color;
        ScreenObject *_master;

    public:
        string& name();
        vector2& position();
        vector2& size();
        vector2& offset();
        string& textureDirectory();
        SDL_Texture* texture();
        SDL_Color& color();
        ScreenObject* master();

        const string& name() const;
        const vector2& position() const;
        const vector2& size() const;
        const vector2& offset() const;
        const string& textureDirectory() const;
        const SDL_Texture* texture() const;
        const SDL_Color& color() const;
        const ScreenObject* master() const;

        void ShiftMaster(ScreenObject *master);
    };  
}

#endif