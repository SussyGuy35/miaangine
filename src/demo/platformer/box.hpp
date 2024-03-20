#pragma once

#include "miaangine.hpp"

class Box : public mia::WorldObject
{
public:
    Box(float x, float y, float sx = 1, float sy = 1);

    void Update(uint8_t message) override;
};