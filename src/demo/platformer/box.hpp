#pragma once

#include "miaangine.hpp"

class Box : public mia::WorldObject
{
public:
    Box(int x, int y, int sx = 1, int sy = 1);

    void Update(uint8_t message) override;
};