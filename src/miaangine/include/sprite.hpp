#ifndef _MIA_SPRITE_HPP
#define _MIA_SPRITE_HPP

#include "common.hpp"

namespace mia
{
    class Sprite
    {
    public:
        Sprite(SDL_Texture *texture, v2i position, v2i size):
            tex(texture),
            pos(position),
            siz(size)
        {}

        virtual ~Sprite()
        {
            DestroyTexture();
        }

        SDL_Texture *tex;
        v2i pos;
        v2i siz;
        
        void DestroyTexture()
        {
            SDL_DestroyTexture(tex);
        }
    };
}

#endif