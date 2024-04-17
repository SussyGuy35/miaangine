#ifndef _MIA_TILEMAP_PALETTE_HPP
#define _MIA_TILEMAP_PALETTE_HPP

#include "common.hpp"

#include "sprite.hpp"

namespace mia
{
    class TilemapPalette
    {
    public:
        TilemapPalette();
        ~TilemapPalette();

    private:
        std::vector<Sprite*> _sprites;
    
    public:
        Sprite* AddSprite(Sprite *sprite);
        void RemoveSprite(Sprite *sprite);

        Sprite* GetSprite(int index);
        SDL_Texture* GetTexture(int index);
    };
}

#endif