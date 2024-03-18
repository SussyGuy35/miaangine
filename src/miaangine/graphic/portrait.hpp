#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <memory>

#include "util/math.hpp"
#include "util/string.hpp"

#include "object/world-object.hpp"

// namespace mia 
// {
    class mia::Portrait
    {
    public:
        Portrait(const char* dir = "", float scale = 1, vector2 offset = vector2::zero());
        Portrait(const char* dir, float scale, float ox, float oy);

        virtual ~Portrait();

    private:
        string _ucName;
        vector2 _ucPosition;

        float _scale;
        vector2 _offset;
        string _textureDirectory;
        SDL_Texture *_texture;
        SDL_Color _color;

        WorldObject *_master;

    public:
        string& name();
        vector2& position();
        float& scale();
        vector2& offset();
        string& textureDirectory();
        SDL_Texture* texture();
        SDL_Color& color();

        WorldObject* master();

        void ShiftMaster(WorldObject *master);
    };
// }

#endif