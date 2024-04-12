#pragma once

#include "miaangine.hpp"

class PlayerState
{
public:
    PlayerState();
    ~PlayerState();

private:
    mia::rect _playerRect;
    bool _touchCheck[4];

public:
    void SetPlayerRect(mia::rect rect);
    void UpdateTouchCheck();
};