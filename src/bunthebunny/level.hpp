#pragma once

#include "miaangine.hpp"
#include "player/player.hpp"

class Level
{
public:
    Level(const char *layoutDir, mia::TilemapPalette *palette);
    ~Level();

public:
    mia::Tilemap map;
    Player *player;

    mia::v2f startPlayerPosition;
    mia::v2f startCameraPosition;
    float startCameraSize;
    
    void ActivateMap();
    void DeActivateMap();

    void ReloadLevel();

    void ReloadPlayer();
    void ReloadCamera();
};