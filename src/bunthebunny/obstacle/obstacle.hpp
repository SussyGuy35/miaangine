#pragma once

#include "miaangine.hpp"
#include "player/player.hpp"
#include "player/player-movement.hpp"

class Obstacle : public mia::Object, public mia::Observer
{
public:
    Obstacle(mia::v2f position): mia::Object(position) {}

    virtual mia::rect GetRect() const = 0;

    virtual void Activate() = 0;
    virtual void DeActivate() = 0;
};