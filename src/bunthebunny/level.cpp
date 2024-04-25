#include "level.hpp"

Level::Level(Player *player):
    camControl(CameraController(player)),
    player(player)
{}

Level::~Level()
{
    DeActivateMap();
    delete map;
}

void Level::MakeMap(const char *layoutDir, mia::TilemapPalette *palette)
{
    map = new mia::Tilemap(layoutDir, palette, {0.925, 0.925});
}

void Level::ActivateMap()
{
    mia::_Renderer().RegisterTilemap(map);
    mia::_Physics().RegisterTilemap(map);
}
void Level::DeActivateMap()
{
    mia::_Renderer().UnregisterTilemap(map);
    mia::_Physics().UnregisterTilemap(map);
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
    camControl.Reset();
}