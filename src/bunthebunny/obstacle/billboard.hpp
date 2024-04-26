#pragma once

#include "obstacle.hpp"

class Billboard : public Obstacle
{
public:
    Billboard(const char *dir, mia::v2i pos, mia::v2i siz , mia::v2f position);
    ~Billboard();

private:
    mia::Portrait *_portrait;

    bool _active = true;

public:
    mia::rect GetRect() const override;
    void Update(int message) override;
    void Activate() override;
    void DeActivate() override;
};