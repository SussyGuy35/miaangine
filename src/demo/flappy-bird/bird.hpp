#pragma once

#include "miaangine.hpp"

class Bird : public mia::WorldObject
{
public:
    Bird();

    void Update(uint8_t message) override;

private:
    const mia::vector2 SIZE;
    const float GRAVITY;
    const float JUMP_VELOCITY;
};