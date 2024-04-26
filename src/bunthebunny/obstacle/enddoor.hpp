#pragma once

#include "obstacle.hpp"

class Enddoor : public Obstacle
{
public:
    Enddoor(Player *player, mia::v2f position = mia::v2f::zero());
    ~Enddoor();

private:
    mia::Portrait *_portrait;

    Player &_player;

public:
    mia::rect GetRect() const override;
    void Update(int message) override;
    void Activate() override;
    void DeActivate() override;
};