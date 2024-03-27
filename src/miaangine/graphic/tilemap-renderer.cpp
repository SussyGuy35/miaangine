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
    void TilemapRenderer::RegisterTilemap(TilemapLayout *layout, TilemapPalette *palette)
    {
        // _tilemaps.push_back(data); //TODO
    }
    // TODO
    #pragma endregion

    #pragma region Update methods
    void TilemapRenderer::Render(SDL_Renderer *renderer)
    {
        
    }
    #pragma endregion

    #pragma region Internal methods

    #pragma endregion
}