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

    std::vector<mia::Sprite*> _sprites;

public:
    mia::Sprite* GetSprite(int index);
};