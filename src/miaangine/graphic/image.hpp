#ifndef _MIA_IMAGE_HPP
#define _MIA_IMAGE_HPP

#include <SDL.h>
#include <SDL_image.h>

#include "util/math.hpp"
#include "util/string.hpp"

#include "object/screen-object.hpp"

// namespace mia
// {
    class mia::Image
    {
    public:
        Image(const char* dir = "", float scale = 1, vector2 offset = vector2::zero());
        Image(const char* dir, float scale, float ox, float oy);

        virtual ~Image();

    private:
        string _ucName;
        vector2 _ucPosition;

        float _scale;
        vector2 _offset;
        string _textureDirectory;
        SDL_Texture *_texture;
        SDL_Color _color;

        ScreenObject *_master;

    public:
        string& name();
        vector2& position();
        float& scale();
        vector2& offset();
        string& textureDirectory();
        SDL_Texture* texture();
        SDL_Color& color();

        ScreenObject* master();

        void ShiftMaster(ScreenObject *master);
    };  
// }

#endif