#include "level.hpp"

Level::Level(Player *player):
    camControl(CameraController(player)),
    player(player)
{
    enddoor = new Enddoor(player, {-100, -100});
}

Level::~Level()
{
    DeActivateMap();
    delete map;
}

void Level::MakeMap(const char *layoutDir, mia::TilemapPalette *palette)
{
    map = new mia::Tilemap(layoutDir, palette, {0.925, 0.925});
}

void Level::AddObstacle(Obstacle* obstacle)
{
    obstacleList.push_back(obstacle);
}

void Level::DeActivateAll()
{
    DeActivateMap();
    player->DeActivate();
    enddoor->DeActivate();
    camControl.DeActive();
}

void Level::ActivateMap()
{
    mia::_Renderer().RegisterTilemap(map);
    mia::_Physics().RegisterTilemap(map);

    enddoor->Activate();
    for (Obstacle *obs : obstacleList)
    {
        obs->Activate();
    }
}
void Level::DeActivateMap()
{
    mia::_Renderer().UnregisterTilemap(map);
    mia::_Physics().UnregisterTilemap(map);

    enddoor->DeActivate();
    for (Obstacle *obs : obstacleList)
    {
        obs->DeActivate();
    }
}

void Level::ReloadLevel()
{
    enddoor->position() = endDoorPosition;
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