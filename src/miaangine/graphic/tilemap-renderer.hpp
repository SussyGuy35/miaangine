#ifndef _MIA_TILEMAP_RENDERER_HPP
#define _MIA_TILEMAP_RENDERER_HPP

#include "util/singleton.hpp"

#include <SDL.h>

#include <vector>
#include "util/math.hpp"
#include "tilemap/tilemap-data.hpp"

namespace mia
{
    struct TilemapData
    {
        TilemapLayout *layout;
        TilemapPalette *palette;
        Vector2<> position;
    };

    class TilemapRenderer : public Singleton<TilemapRenderer>
    {
    private:
        friend class Singleton<TilemapRenderer>;
        TilemapRenderer();
        ~TilemapRenderer();

    private:
        std::vector<TilemapData> _tilemapDatas;

    public:
        void RegisterTilemap(TilemapLayout *layout, TilemapPalette *palette, const Vector2<> &position);
        // TODO
        void Render(SDL_Renderer *renderer);

    private:
        void RenderATilemap(TilemapData &data);
    };
}

#endif