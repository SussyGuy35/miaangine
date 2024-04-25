#pragma once

#include "obstacle.hpp"

class Spring : public Obstacle
{
public:
    Spring(Player *player, mia::v2f position = mia::v2f::zero());
    ~Spring();

private:
    mia::Portrait *_portrait;

    Player &_player;
    mia::Sprite *_useSprite;
    mia::Sprite *_unuseSprite;

    float _additionalSpeed;
    float _cooldown;

    bool _active = true;

public:
    mia::rect GetRect() const override;
    void Update(int message) override;
    void Activate() override;
    void DeActivate() override;
};