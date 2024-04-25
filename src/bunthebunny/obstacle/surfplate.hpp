#pragma once

#include "obstacle.hpp"

class Surfplate : public Obstacle
{
public:
    Surfplate(Player *player, mia::v2f position = mia::v2f::zero());
    ~Surfplate();

private:
    mia::Portrait *_portrait;

    Player &_player;

    float _additionalSpeed;
    float _cooldown;

    bool _active = true;

public:
    mia::rect GetRect() const override;
    void Update(int message) override;
};