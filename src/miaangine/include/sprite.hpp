#ifndef _MIA_SPRITE_HPP
#define _MIA_SPRITE_HPP

#include "common.hpp"

#include "game.hpp"

namespace mia
{
    class Sprite
    {
    public:
        Sprite(const char *source, mia::v2f position, mia::v2f size, mia::v2f pivot):
            source(source),
            position(position),
            size(size),
            pivot(pivot)
        {
            texture = IMG_LoadTexture(Game::Instance().renderer, source); //TODO safety
        }

        virtual ~Sprite()
        {
            SDL_DestroyTexture(texture);
        }

        mia::string source;
        mia::v2f position;
        mia::v2f size;
        mia::v2f pivot;
        SDL_Texture *texture;
    };
}

#endif