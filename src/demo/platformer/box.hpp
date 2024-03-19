#pragma once

#include "miaangine.hpp"

class Box : public mia::WorldObject
{
public:
    Box(int x, int y, int sx = 10, int sy = 10);

    void Update(uint8_t message) override;
};