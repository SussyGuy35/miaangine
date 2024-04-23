#pragma once

#include "miaangine.hpp"

class PlayerMovement;
class PlayerVisual;
class PlayerUI;
class Player : public mia::Object, public mia::Observer
{
public:
    Player(int x, int y);
    ~Player();

private:
    mia::Portrait *_portrait;
    mia::Body *_body;

    PlayerMovement *_movement;
    PlayerVisual *_visual;

public:
    mia::Portrait& portrait();
    mia::Body& body();
    PlayerMovement& movement();
    PlayerVisual& visual();

    void Update(int message) override;
};