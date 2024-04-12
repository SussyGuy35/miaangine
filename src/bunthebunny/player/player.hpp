#pragma once

#include "miaangine.hpp"

class PlayerMovement;
class Player : public mia::Object, public mia::Observer
{
public:
    Player(int x, int y);
    ~Player();

private:
    mia::Portrait* _portrait;
    mia::Body* _body;

    PlayerMovement *_movement;

public:
    mia::Portrait& portrait();
    mia::Body& body();

    void Update(int message) override;
};