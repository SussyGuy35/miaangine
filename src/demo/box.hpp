#pragma once

#include "miaangine.hpp"

class Box : public mia::Portrait
{
public:
    Box():
        Portrait(mia::Vector2(100, 10), mia::Vector2(100, 100))
    {}

    void Update(uint8_t message) override;
};