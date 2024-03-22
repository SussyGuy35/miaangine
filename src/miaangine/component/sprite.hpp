#ifndef _MIA_SPRITE_HPP
#define _MIA_SPRITE_HPP

#ifndef _MIA_OBJECT_COMPONENT_INTERFACE_HPP
#include "interface/object-component-interface.hpp" 
#endif

#include <SDL.h>
#include "util/math.hpp"
#include <string>

namespace mia
{
    class Sprite : public IObjectComponent
    {
    public:
        Portrait(Vector2<> scale = Vector2<>::zero(), Vector2<> offset = Vector2<>::zero());
        Portrait(float sx, float sy, float ox = 0, float oy = 0);

        virtual ~Portrait();

    private:
        // Interface required
        bool _isActive
        WorldObject *_master;

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
        Components getType() const { return _COMPONENT_SPRITE; }
        bool isActive() const { return _isActive; }
        bool setActive(bool newState) { return _isActive = state; }
        IGameObject& master() { return *_master; } 
        const IGameObject& master() const { return *_master; }
    };
}

#endif