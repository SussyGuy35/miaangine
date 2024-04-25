#include "game-manager.hpp"

GameManager::GameManager()
{
    mia::_Events().RegisterObserver(this);
}

void GameManager::Init(Player *player)
{
    this->player = player,

    mapPalette = new mia::TilemapPalette();
    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/tileset-16x16.png");
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

void GameManager::MakeLevel()
{
    Level *level = new Level(player);
    levelList.push_back(level);
    
    level->MakeMap("D:/SDL/miaangine/asset/map.txt", mapPalette);

    level->startPlayerPosition = {0, 5};

    level->camControl.startPosition = {0, 0};
    level->camControl.startSize = 45;
    level->camControl.leftBound = 0;
    level->camControl.rightBound = 200;
    level->camControl.idealPlayerOffset = 5;
    level->camControl.camFollowingBound = 7;
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

}