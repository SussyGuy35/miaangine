#include "game-manager.hpp"

#include "obstacle/spring.hpp"
#include "obstacle/surfplate.hpp"
#include "obstacle/spike-up.hpp"

#include <fstream>
#include <string>

GameManager::GameManager()
{
    mia::_Events().RegisterObserver(this);
}

void GameManager::Init(Player *player)
{
    this->player = player,

    mapPalette = new mia::TilemapPalette();
    mia::_SpriteHandler().SetSource("./../asset/tileset-16x16.png");
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({0 , 32}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({16, 32}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({32, 32}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({0 , 16}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({16, 16}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({32, 16}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({0 , 0 }, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({16, 0 }, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({32, 0 }, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({48, 0 }, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({64, 0 }, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({48, 16}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({64, 16}, {16, 16}));
}

void GameManager::MakeLevel(const char *dir)
{
    std::ifstream input;
    input.open(dir);

    if (!input.is_open()) 
    {
        printf("No source for GameManager");
        return;
    }

    Level *level = new Level(player);
    levelList.push_back(level);

    std::string mapLayoutDir;
    input >> mapLayoutDir;
    level->MakeMap(mapLayoutDir.c_str(), mapPalette);

    int obstacleCount;

    input >> obstacleCount;
    for (int i = 0; i < obstacleCount; i++)
    {
        int x, y;
        input >> x >> y;

        Spring *spring = new Spring(player, {float(x * .925), float(y * .925)});
        level->AddObstacle(spring);
    }

    input >> obstacleCount;
    for (int i = 0; i < obstacleCount; i++)
    {
        int x, y;
        input >> x >> y;

        Surfplate *surf = new Surfplate(player, {float(x * .925), float(y * .925)});
        level->AddObstacle(surf);
    }

    input >> obstacleCount;
    for (int i = 0; i < obstacleCount; i++)
    {
        int x, y, c;
        input >> x >> y >> c;

        UpSpike *spike = new UpSpike(player, {float(x * .925), float(y * .925)}, c);
        level->AddObstacle(spike);
    }

    input >> level->startPlayerPosition.x >> level->startPlayerPosition.y;

    input >> level->camControl.startPosition.x >> level->camControl.startPosition.y;
    input >> level->camControl.startSize;
    input >> level->camControl.leftBound;
    input >> level->camControl.rightBound;
    input >> level->camControl.idealPlayerOffset;
    input >> level->camControl.camFollowingBound;
}

void GameManager::LoadLevel(int index)
{
    if (index < 0 || index >= levelList.size()) return;

    Level &level = *levelList[index];
    if (index == _currentLevel)
    {
        level.ReloadLevel();
    }
    else 
    {
        if (_currentLevel > 0 && _currentLevel < levelList.size()) levelList[_currentLevel]->DeActivateMap();

        level.ActivateMap();
        level.ReloadLevel();
    }

    _currentLevel = index;
}

void GameManager::ReloadLevel()
{
    if (_currentLevel < 0 || _currentLevel >= levelList.size()) return;
    
    levelList[_currentLevel]->ReloadLevel();
}

void GameManager::Update(int message)
{
    if (message == mia::_EVENT_AFTER_PHYSICS_CALCULATION)
    {
        if (player->position().y < -10) ReloadLevel();
    }
}