#pragma once

#include "miaangine.hpp"

#include "player.hpp"

class PlayerVisual
{
public:
    PlayerVisual(Player *manager);
    ~PlayerVisual();

private:
    Player *_manager;

    mia::Sprite *_sprite;
    mia::Clip _idleAnimation;
    mia::Clip _runAnimation;

    float count = 0.2; //FIXME

public:
    mia::Sprite* GetSprite();

    void Update();
};