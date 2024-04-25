#pragma once

#include "obstacle.hpp"

class Spike : public Obstacle
{
public:
    Spike(Player *player, mia::v2f position = mia::v2f::zero(), int size = 1);
    ~Spike();

private:
    Player &_player;

    int _size;

    float _additionalSpeed;
    float _cooldown;

public:
    mia::rect GetRect() const override;
    void Update(int message) override;
};