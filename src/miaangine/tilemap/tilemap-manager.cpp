#include "tilemap-manager.hpp"

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
        _tilemapList.push_back(std::make_pair<TilemapLayout*, TilemapPalette*>(layout, palette));
    }

    bool TilemapManager::Load(int index, Vector2<> position = Vector2<>::zero(), Vector2<> scale = Vector2<>::one())
    {
        //TODO
    }
    bool TilemapManager::Load(int index, float px, float py, float sx, float sy)
    {

    }
}