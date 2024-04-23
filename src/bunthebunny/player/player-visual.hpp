#pragma once

#include "miaangine.hpp"

#include "player.hpp"

class PlayerVisual
{
public:
    PlayerVisual(Player *manager);
    ~PlayerVisual();

private:
    Player &_manager;

    mia::Clip _idleAnimation;
    mia::Clip _runAnimation;
    mia::Clip _jumpAnimation;
    mia::Clip _fallAnimation;
    
    mia::Clip *_currentClip;

    float _frameTimer = 0.1; 

public:
    Player& GetManager();

    mia::Sprite* GetSprite();

    void Update();

    void PlayCurrentAnimation();
};