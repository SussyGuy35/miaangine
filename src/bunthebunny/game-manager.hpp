#pragma once

#include "miaangine.hpp"

#include "level.hpp"
#include "player/player.hpp"

class GameManager : public mia::Observer, public mia::Singleton<GameManager>
{
private:
    friend class mia::Singleton<GameManager>;
    GameManager();

private:
    int _currentLevel = -1;

public:
    Player *player;

    mia::TilemapPalette *mapPalette;
    std::vector<Level*> levelList;

    void Init(Player *player);

    void MakeLevel();

    void LoadLevel(int index);
    void ReloadLevel();

    void Update(int message) override;
}; 