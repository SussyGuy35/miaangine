#ifndef _MIA_SPRITE_HPP
#define _MIA_SPRITE_HPP

#include "object/object.hpp"

#include <SDL.h>
#include "util/math.hpp"
#include <string>

namespace mia
{
    class Sprite
    {
    public:
        Sprite(Vector2<> scale = Vector2<>::zero(), Vector2<> offset = Vector2<>::zero());
        Sprite(float sx, float sy, float ox = 0, float oy = 0);

        virtual ~Sprite();

    private:
        // Attributes
        bool _isActive;
        Object *_master;

        Vector2<> _scale;
        Vector2<> _offset;
        std::string _textureDirectory;

        SDL_Texture *_texture;
        SDL_Color _color;

        bool _hasTexture;
    
    public:
        // Attributes accessing
        bool isActive() const;
        const Object& master() const;
        const Vector2<>& scale() const;
        const Vector2<>& offset() const;
        const char* getTextureDir() const;
        const SDL_Texture* getTexture() const;
        const SDL_Color& color() const;
        bool hasTexture() const;

        bool SetActive(bool newState);
        Object& master();
        Vector2<>& scale();
        Vector2<>& offset();
        SDL_Color& color();

        // Methods
        SDL_Texture* Load(const char* dir);
    };
}

#endif