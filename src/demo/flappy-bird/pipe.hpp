#pragma once

#include "miaangine.hpp"

class Pipe : public mia::WorldObject
{
public:
    Pipe();

    void Update(uint8_t message) override;

private:
    const int PIPE_HOLE_RADIUS;
    const int PIPE_WIDTH;
    const float SPEED;

public:
    bool moving;

    void Reset();
};