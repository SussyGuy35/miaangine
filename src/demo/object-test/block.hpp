#pragma once

#include "miaangine.hpp"

class Block : public mia::WorldObject
{
public:
    Block(float x, float y, float speed, float dir, float colorOff);

    void Update(uint8_t message) override;

private:
    const float SPEED;
    const float DIR;

    mia::vector2 direction;
};