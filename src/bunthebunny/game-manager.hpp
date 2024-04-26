#pragma once

#include "miaangine.hpp"

#include "level.hpp"
#include "player/player.hpp"
#include "main-menu.hpp"

class GameManager : public mia::Observer, public mia::Singleton<GameManager>
{
private:
    friend class mia::Singleton<GameManager>;
    GameManager();

private:
    int _currentLevel = 10000;

    mia::string _scoreDir;

public:
    Player *player;

    MainMenu *mainMenu;
    mia::TilemapPalette *mapPalette;
    std::vector<Level*> levelList;

    void Init(Player *player, const char *scoreDir);

    float GetScore(int index);
    void SetScore(int index, float value);

    void MakeLevel(const char *dir);

    void LoadMainMenu();
    void DeActivateMenu();

    void LoadLevel(int index);
    void ReloadLevel();

    void Update(int message) override;
}; 