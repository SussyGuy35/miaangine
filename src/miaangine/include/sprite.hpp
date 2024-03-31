#ifndef _MIA_SPRITE_HPP
#define _MIA_SPRITE_HPP

#include "common.hpp"

namespace mia
{
    class Sprite
    {
    public:
        Sprite(SDL_Texture *texture, mia::v2i position, mia::v2i size, mia::v2f pivot):
            texture(texture),
            position(position),
            size(size),
            pivot(pivot)
        {}

        ~Sprite()
        {}

        SDL_Texture *texture;
        mia::v2i position;
        mia::v2i size;
        mia::v2f pivot;

        void DestroyTexture()
        {
            SDL_DestroyTexture(texture);
        }
    };
}

#endif