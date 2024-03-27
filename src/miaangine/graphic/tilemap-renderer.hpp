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
        Vector2<> size;

        TilemapData(TilemapLayout *layout, TilemapPalette *palette, const Vector2<> &position, const Vector2<> &size): 
            layout(layout), palette(palette), position(position), size(size)
        {}
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
        void RegisterTilemap(TilemapLayout *layout, TilemapPalette *palette, const Vector2<> &position, const Vector2<> &size);
        // TODO
        void Render(SDL_Renderer *renderer);

    private:
        void RenderATilemap(SDL_Renderer *renderer, TilemapData &data);
        void RenderATile(SDL_Renderer *renderer, SDL_Texture *texture, Vector2<> position, Vector2<> size);
    };
}

#endif