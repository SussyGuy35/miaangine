#include "tilemap-renderer.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <algorithm>

#include "core/engine-components.hpp"
#include "miaangine-global-constant.hpp"

namespace mia
{
    #pragma region Constructor_Destructor
    TilemapRenderer::TilemapRenderer()
    {}

    TilemapRenderer::~TilemapRenderer()
    {}
    #pragma endregion

    #pragma region Registration methods
    void TilemapRenderer::RegisterTilemap(TilemapLayout *layout, TilemapPalette *palette, const Vector2<> &position, const Vector2<> &size)
    {
        _tilemapDatas.push_back(TilemapData(layout, palette, position, size));
    }
    // TODO
    #pragma endregion

    #pragma region Update methods
    void TilemapRenderer::Render(SDL_Renderer *renderer)
    {
        for (TilemapData &data : _tilemapDatas)
        {
            RenderATilemap(renderer, data);
        }
    }
    #pragma endregion

    #pragma region Internal methods
    void TilemapRenderer::RenderATilemap(SDL_Renderer *renderer, TilemapData &data)
    {
        TilemapLayout *layout = data.layout; 
        TilemapPalette *palette = data.palette; 
        Vector2<> position = data.position;
        Vector2<> size = data.size;

        int width = layout->width();
        int height = layout->height();
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (layout->getData(i, j) <= 0) continue;

                RenderATile(renderer, palette->texture(layout->getData(i, j)), position + Vector2<>(size.x * j, size.y * i), size);
            }
        }
    }
    void TilemapRenderer::RenderATile(SDL_Renderer *renderer, SDL_Texture *texture, Vector2<> position, Vector2<> size)
    {
        SDL_Rect rect;

        float unitSize = (generic().windowWidth / camera().size());

        int w = 0, h = 0;
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);

        float displayW = 1.0 * w * unitSize / PIXEL_PER_UNIT;
        float displayH = 1.0 * h * unitSize / PIXEL_PER_UNIT;
        float displayX = (position.x - camera().position().x) * unitSize;
        float displayY = generic().windowHeight - displayH - (position.y - camera().position().y) * unitSize;

        rect.x = static_cast<int>(displayX);
        rect.y = static_cast<int>(displayY); 
        rect.w = static_cast<int>(displayW);
        rect.h = static_cast<int>(displayH);

        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
    #pragma endregion
}