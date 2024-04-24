#pragma once

#include "miaangine.hpp"

#include "player.hpp"

class PlayerUI
{
public:
    PlayerUI(Player *manager);
    ~PlayerUI();

private:
    Player &_manager;

    mia::UI *_meter;
    mia::Image *_metterImg;

    float _maxMeterHeight;
    float _maxMeterValue;

public:
    void Update();
};