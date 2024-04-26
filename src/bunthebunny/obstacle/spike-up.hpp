#pragma once

#include "obstacle.hpp"

class UpSpike : public Obstacle
{
public:
    UpSpike(Player *player, mia::v2f position = mia::v2f::zero(), int size = 1);
    ~UpSpike();

private:
    Player &_player;

    std::vector<mia::Portrait*> _portraits;    

    int _size;

    float _additionalSpeed;
    float _cooldown;

public:
    mia::rect GetRect() const override;
    void Update(int message) override;
    void Activate() override;
    void DeActivate() override;
};