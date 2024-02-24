#pragma once

#include "miaangine.hpp"

class Box : public mia::WorldObject
{
public:
    Box(float x, float y):
        WorldObject(x, y)
    {}

    void Update(uint8_t message) override;
};