#ifndef _MIA_TILEMAP_RENDERER_HPP
#define _MIA_TILEMAP_RENDERER_HPP

#include "util/singleton.hpp"

#include <SDL.h>

#include <vector>
#include "util/math.hpp"
#include "tilemap/tilemap-data.hpp"

namespace mia
{
    class TilemapRenderer : public Singleton<TilemapRenderer>
    {
    private:
        friend class Singleton<TilemapRenderer>;
        TilemapRenderer();
        ~TilemapRenderer();

    private:
        std::vector<TilemapLayout*> _tilemaps;

    public:
        void RegisterTilemap(TilemapLayout *layout, TilemapPalette *palette);
        // TODO
        void Render(SDL_Renderer *renderer);

    private:
        void RenderATilemap(TilemapLayout &data);
    };
}

#endif