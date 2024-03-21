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
        Portrait(const char* dir = "", Vector2 scale = Vector2::one(), Vector2 offset = Vector2::zero());
        Portrait(const char* dir, float sx, float sy, float ox = 0, float oy = 0);
        Portrait(Vector2 scale, Vector2 offset = Vector2::zero());
        Portrait(float sx, float sy, float ox = 0, float oy = 0);

        virtual ~Portrait();

    private:
        string _ucName;
        Vector2 _ucPosition;

        Vector2 _scale;
        Vector2 _offset;
        string _textureDirectory;
        SDL_Texture *_texture;
        SDL_Color _color;
        WorldObject *_master;

    public:
        string& name();
        Vector2& position();
        Vector2& scale();
        Vector2& offset();
        string& textureDirectory();
        SDL_Texture* texture();
        SDL_Color& color();
        WorldObject* master();

        const string& name() const;
        const Vector2& position() const;
        const Vector2& scale() const;
        const Vector2& offset() const;
        const string& textureDirectory() const;
        const SDL_Texture* texture() const;
        const SDL_Color& color() const;
        const WorldObject* master() const;

        void ShiftMaster(WorldObject *master);
    };
}

#endif