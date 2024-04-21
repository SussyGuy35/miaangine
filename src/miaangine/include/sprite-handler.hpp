#ifndef _MIA_SPRITE_HANDLER_HPP
#define _MIA_SPRITE_HANDLER_HPP

#include "common.hpp"

#include "sprite.hpp"
#include "game.hpp"

namespace mia
{
    class SpriteHandler : public Singleton<SpriteHandler>
    {
    private:
        friend class Singleton<SpriteHandler>;
        SpriteHandler();
        ~SpriteHandler();

    private:
        string _source;
        SDL_Texture *_texture;

    public:
        const char* getSource() const;
        const SDL_Texture* getTexture() const;

        void SetSource(const char *source);

        Sprite* MakeCut(v2i position, v2i size);
    };
}

#endif