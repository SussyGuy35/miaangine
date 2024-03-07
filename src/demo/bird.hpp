#pragma once

#include "miaangine.hpp"

class Bird : public mia::WorldObject
{
public:
    Bird(float x, float y);

    void Update(uint8_t message) override;

private:
    const mia::Vector2 SIZE;
    const float GRAVITY;
    const float JUMP_VELOCITY;
};