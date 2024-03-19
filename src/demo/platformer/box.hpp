#pragma once

#include "miaangine.hpp"

class Box : public mia::WorldObject
{
public:
    Box(int x, int y, int sx = 5, int sy = 5);

    void Update(uint8_t message) override;
};