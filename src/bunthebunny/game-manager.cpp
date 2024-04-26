#include "game-manager.hpp"

#include "obstacle/spring.hpp"
#include "obstacle/surfplate.hpp"
#include "obstacle/spike-up.hpp"
#include "obstacle/billboard.hpp"

#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

GameManager::GameManager()
{
    mia::_Events().RegisterObserver(this);
}

void GameManager::Init(Player *player, const char *scoreDir)
{
    this->player = player,
    _scoreDir = scoreDir;

    mainMenu = new MainMenu();

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

    mia::_Audio().Play(mia::_Audio().Insert("./../asset/ost.wav", 0), -1);
    mia::_Audio().Insert("./../asset/jump.wav", 1);
    mia::_Audio().Insert("./../asset/land.wav", 2);
    mia::_Audio().Insert("./../asset/dash.wav", 3);
    mia::_Audio().Insert("./../asset/buff.wav", 4);
    mia::_Audio().Insert("./../asset/dead.wav", 5);
}

int GameManager::GetCurrentLevel()
{
    return _currentLevel;
}

float GameManager::GetScore(int index)
{
    std::ifstream input;
    input.open(_scoreDir.str());

    if (!input.is_open())
    {
        SDL_Log("No source for GameManager");
        return 3599.59;
    }

    float value = 0;
    for (int i = 0; i <= index; i++) input >> value;

    input.close();

    return value;
}
void GameManager::SetScore(int index, float value)
{
    float newscore[3] {0,0,0};

    std::ifstream input;
    input.open(_scoreDir.str());

    for (int i = 0; i < 3; i++) input >> newscore[i];
    input.close();

    newscore[index] = value;

    std::ofstream output(_scoreDir.str(), std::ios::trunc);

    for (int i = 0; i < 3; i++) output << newscore[i] << "\n";

    output.close();
}

void GameManager::MakeLevel(const char *dir)
{
    std::ifstream input;
    input.open(dir);

    if (!input.is_open()) 
    {
        SDL_Log("No source for GameManager");
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
        std::string dir;
        mia::v2i pos, siz;
        float x, y;
        input >> dir >> pos.x >> pos.y >> siz.x >> siz.y >> x >> y;

        Billboard *billboard = new Billboard(dir.c_str(), pos, siz, {x, y});
        level->AddObstacle(billboard);
    }

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
    input >> level->endDoorPosition.x >> level->endDoorPosition.y;

    input >> level->camControl.startPosition.x >> level->camControl.startPosition.y;
    input >> level->camControl.startSize;
    input >> level->camControl.leftBound;
    input >> level->camControl.rightBound;
    input >> level->camControl.idealPlayerOffset;
    input >> level->camControl.camFollowingBound;

    input.close();
}

void GameManager::LoadMainMenu()
{
    if (_currentLevel < 0) return;

    if (_currentLevel >= 0 && _currentLevel < levelList.size()) 
    {
        levelList[_currentLevel]->DeActivateAll();
    }
    player->DeActivate();

    mainMenu->Activate();

    _currentLevel = -1;
}

void GameManager::DeActivateMenu()
{
    mainMenu->DeActivate();

    _currentLevel = 10000;
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
        if (_currentLevel >= 0 && _currentLevel < levelList.size()) 
        {
            levelList[_currentLevel]->DeActivateMap();
        }
        if (_currentLevel < 0) 
        {
            mainMenu->DeActivate();
        }
        
        level.ActivateMap();
        level.ReloadLevel();
        timer = 0;
    }

    _currentLevel = index;
}

void GameManager::ReloadLevel()
{
    if (_currentLevel < 0 || _currentLevel >= levelList.size()) return;
    
    levelList[_currentLevel]->ReloadLevel();
    timer = 0;
}

void GameManager::Update(int message)
{
    if (message == mia::_EVENT_AFTER_PHYSICS_CALCULATION)
    {
        if (player->position().y < -10) ReloadLevel();

        timer += mia::_Time().deltaTime();
    }
}

void GameManager::RegisterTimeScore(int index)
{
    if (timer < GetScore(index))
    {
        SetScore(index, timer);
    }
    timer = 0;
}

std::string GameManager::SecondsToTimer(float value) 
{
    int minutes = static_cast<int>(value / 60);
    value -= minutes * 60;
    int seconds = static_cast<int>(value);
    value -= seconds;
    int ticks = static_cast<int>(value * 100); 

    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << minutes << ":"
        << std::setw(2) << seconds << ":"
        << std::setw(2) << ticks;

    return ss.str();
}