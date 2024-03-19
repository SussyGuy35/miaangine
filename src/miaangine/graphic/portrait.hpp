#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include <SDL.h>
#include <SDL_image.h>

#include "util/math.hpp"
#include "util/string.hpp"

#include "object/world-object.hpp"

namespace mia 
{
    class Portrait
    {
    public:
        Portrait(const char* dir = "", vector2 scale = vector2::one(), vector2 offset = vector2::zero());
        Portrait(const char* dir, float sx, float sy, float ox, float oy);
        Portrait(vector2 scale, vector2 offset = vector2::zero());
        Portrait(float sx, float sy, float ox = 0, float oy = 0);

        virtual ~Portrait();

    private:
        string _ucName;
        vector2 _ucPosition;

        vector2 _scale;
        vector2 _offset;
        string _textureDirectory;
        SDL_Texture *_texture;
        SDL_Color _color;

        WorldObject *_master;

    public:
        string& name();
        vector2& position();
        vector2& scale();
        vector2& offset();
        string& textureDirectory();
        SDL_Texture* texture();
        SDL_Color& color();

        WorldObject* master();

        void ShiftMaster(WorldObject *master);
    };
}

#endif