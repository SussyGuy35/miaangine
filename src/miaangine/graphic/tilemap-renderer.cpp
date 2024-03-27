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
    void TilemapRenderer::RegisterTilemap(TilemapLayout *layout, TilemapPalette *palette, const Vector2<> &position)
    {
        _tilemapDatas.push_back({layout, palette, position});
    }
    // TODO
    #pragma endregion

    #pragma region Update methods
    void TilemapRenderer::Render(SDL_Renderer *renderer)
    {
        for (TilemapData &data : _tilemapDatas)
        {
            RenderATilemap(data);
        }
    }
    #pragma endregion

    #pragma region Internal methods
    void TilemapRenderer::RenderATilemap(TilemapData &data)
    {
        TilemapLayout *layout = data.layout; 
        TilemapPalette *palette = data.palette; 
        Vector2<> position = data.position;

        //TODO
    }
    #pragma endregion
}