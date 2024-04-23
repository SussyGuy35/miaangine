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

    float _timePerFrame = 0.1; 
    float _frameTimer = _timePerFrame;

public:
    Player& GetManager();

    void Update();

    void PlayCurrentAnimation();
    void UpdatePortrait();
};