#ifndef _MIA_SPRITE_HPP
#define _MIA_SPRITE_HPP

#include <SDL.h>
#include "util/math.hpp"
#include <string>

namespace mia
{
    class Sprite : public IObjectComponent
    {
    public:
        Sprite(Vector2<> scale = Vector2<>::zero(), Vector2<> offset = Vector2<>::zero());
        Sprite(float sx, float sy, float ox = 0, float oy = 0);

        virtual ~Sprite();

    private:
        // Interface required
        bool _isActive;
        IGameObject *_master;

        // Attributes
        Vector2<> _scale;
        Vector2<> _offset;
        std::string _textureDirectory;

        SDL_Texture *_texture;
        SDL_Color _color;
    
    public:
        // Attributes accessing
        const Vector2<>& scale() const;
        const Vector2<>& offset() const;
        const char* getTextureDir() const;

        Vector2<>& scale();
        Vector2<>& offset();

        // Abstract methods
        Components getType() const;
        bool isActive() const;
        bool SetActive(bool newState);
        IGameObject& master();
        const IGameObject& master() const;
    };
}

#endif