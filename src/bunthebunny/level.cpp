#include "level.hpp"

Level::Level(const char *layoutDir, mia::TilemapPalette *palette):
    map(mia::Tilemap(layoutDir, palette, {0.925, 0.925}))
{}

Level::~Level()
{
    DeActivateMap();
}

void Level::ActivateMap()
{
    mia::_Renderer().RegisterTilemap(&map);
    mia::_Physics().RegisterTilemap(&map);
}
void Level::DeActivateMap()
{
    mia::_Renderer().UnregisterTilemap(&map);
    mia::_Physics().UnregisterTilemap(&map);
}

void Level::ReloadLevel()
{
    ReloadPlayer();
    ReloadCamera();
}

void Level::ReloadPlayer()
{
    player->DeActivate();
    player->Activate();
    player->position() = startPlayerPosition;
}

void Level::ReloadCamera()
{
    mia::_Camera().position() = startCameraPosition;
    mia::_Camera().size() = startCameraSize;
}