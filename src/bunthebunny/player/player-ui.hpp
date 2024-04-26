#pragma once

#include "miaangine.hpp"

#include "player.hpp"
#include "ui-main.hpp"

class PlayerUI
{
public:
    PlayerUI(Player *manager);
    ~PlayerUI();

private:
    Player &_manager;

    UIMain _mainUI;
    mia::UI *_meter;
    mia::Image *_metterImg;

    mia::UI *_timer;

    float _maxMeterHeight;
    float _maxMeterValue;

public:
    void Activate();
    void DeActivate();

    void Update();
};