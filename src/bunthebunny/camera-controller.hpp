#pragma once

#include "miaangine.hpp"
#include "player/player.hpp"

class CamaraController : public mia::Observer
{
public:
    CamaraController(Player *player);
    ~CamaraController();

public:
    float leftBound;
    float rightBound;

    float idealPlayerOffset;
    float camFollowingBound;

private:
    Player *_player;

    float _smooth;

    bool _following = false;

public:
    void Update(int message) override;
};