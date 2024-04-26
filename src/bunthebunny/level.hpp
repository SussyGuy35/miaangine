#pragma once

#include "miaangine.hpp"
#include "player/player.hpp"
#include "camera-controller.hpp"
#include "obstacle/obstacle.hpp"
#include "obstacle/enddoor.hpp"

class Level
{
public:
    Level(Player *player);
    ~Level();

public:
    mia::Tilemap *map;
    std::vector<Obstacle*> obstacleList;
    Enddoor *enddoor;

    CameraController camControl;

    Player *player;

    mia::v2f startPlayerPosition;
    mia::v2f endDoorPosition;

    void MakeMap(const char *layoutDir, mia::TilemapPalette *palette);
    void AddObstacle(Obstacle* obstacle);
    
    void DeActivateAll();

    void ActivateMap();
    void DeActivateMap();

    void ReloadLevel();

    void ReloadPlayer();
    void ReloadCamera();
};