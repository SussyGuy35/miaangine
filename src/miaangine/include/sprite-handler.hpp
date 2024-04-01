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
        mia::string _source;
        SDL_Texture *_texture;

        std::vector<Sprite*> _sprites;

    public:
        const char* getSource() const;
        const SDL_Texture* getTexture() const;

        void SetSource(const char *source);

        Sprite* MakeCut(mia::v2i position, mia::v2i size);
        void DestroyCut(Sprite *sprite);
        void DestroyAllCuts(); 
    };
}

#endif