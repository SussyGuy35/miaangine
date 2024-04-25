#pragma once

#include "miaangine.hpp"
#include "player/player.hpp"
#include "camera-controller.hpp"
#include "obstacle/obstacle.hpp"

class Level
{
public:
    Level(Player *player);
    ~Level();

public:
    mia::Tilemap *map;
    std::vector<Obstacle*> obstacleList;

    CameraController camControl;

    Player *player;

    mia::v2f startPlayerPosition;

    void MakeMap(const char *layoutDir, mia::TilemapPalette *palette);
    void AddObstacle(Obstacle* obstacle);
    
    void ActivateMap();
    void DeActivateMap();

    void ReloadLevel();

    void ReloadPlayer();
    void ReloadCamera();
};