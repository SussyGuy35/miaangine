#include "tilemap-manager.hpp"

#include "graphic/tilemap-renderer.hpp" // wtf ? how this shiet work

namespace mia
{
    #pragma region Constructor_Destructor
    TilemapManager::TilemapManager()
    {}

    TilemapManager::~TilemapManager()
    {}
    #pragma endregion

    int TilemapManager::AddTilemap(TilemapLayout *layout, TilemapPalette *palette)
    {
        _tilemapList.push_back(std::make_pair(layout, palette));
    }

    bool TilemapManager::Load(int index, Vector2<> position, Vector2<> size)
    {
        TilemapRenderer::Instance().RegisterTilemap(_tilemapList[index].first, _tilemapList[index].second, position, size);
    }
    bool TilemapManager::Load(int index, float px, float py, float sx, float sy)
    {
        TilemapRenderer::Instance().RegisterTilemap(_tilemapList[index].first, _tilemapList[index].second, Vector2<>(px, py), Vector2<>(sx, sy));
    }
}