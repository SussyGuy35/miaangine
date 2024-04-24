#pragma once

#include "miaangine.hpp"

class PlayerMovement;
class PlayerVisual;
class PlayerUI;
class Player : public mia::Object, public mia::Observer
{
public:
    Player(float x, float y);
    ~Player();

private:
    bool _active;

    mia::Portrait *_portrait;
    mia::Body *_body;

    PlayerMovement *_movement;
    PlayerVisual *_visual;
    PlayerUI *_ui;

public:
    mia::Portrait& portrait();
    mia::Body& body();
    PlayerMovement& movement();
    PlayerVisual& visual();
    PlayerUI& ui();

    void Update(int message) override;

    void Activate();
    void DeActivate();
};