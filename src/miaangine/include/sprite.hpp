#ifndef _MIA_SPRITE_HPP
#define _MIA_SPRITE_HPP

#include "common.hpp"

namespace mia
{
    class Sprite
    {
    public:
        Sprite(SDL_Texture *texture, mia::v2i position, mia::v2i size):
            texture(texture),
            position(position),
            size(size)
        {}

        ~Sprite()
        {}

        SDL_Texture *texture;
        mia::v2i position;
        mia::v2i size;
        
        void DestroyTexture()
        {
            SDL_DestroyTexture(texture);
        }
    };
}

#endif