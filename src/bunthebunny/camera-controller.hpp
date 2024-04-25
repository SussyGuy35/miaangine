#pragma once

#include "miaangine.hpp"
#include "player/player.hpp"

class CameraController : public mia::Observer
{
public:
    CameraController(Player *player);
    ~CameraController();

private:
    Player *_player;

    bool _following = false;

public:
    mia::v2f startPosition;
    float startSize;

    float leftBound;
    float rightBound;

    float idealPlayerOffset;
    float camFollowingBound;

    float smooth;

public:
    void Reset();

    void Update(int message) override;
};