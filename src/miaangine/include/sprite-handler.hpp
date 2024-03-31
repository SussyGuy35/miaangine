#ifndef _MIA_SPRITE_HANDLER_HPP
#define _MIA_SPRITE_HANDLER_HPP

#include "common.hpp"

#include "sprite.hpp"
#include "game.hpp"

namespace mia
{
    class SpriteHandler
    {
    public:
        SpriteHandler(const char *source = "");

        virtual ~SpriteHandler();

    private:
        mia::string _source;
        SDL_Texture *_texture;

        std::vector<Sprite*> _sprites;

    public:
        const char* getSource() const;
        const SDL_Texture* getTexture() const;

        void ChangeTexture(const char *newSource);

        void MakeCut(mia::v2i position, mia::v2i size, mia::v2f pivot = mia::v2f(0.5, 0.5));
        // TODO ADd remove cut
        void DestroyCuts(); 
    };
}

#endif