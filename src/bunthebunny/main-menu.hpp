#pragma once

#include "miaangine.hpp"

class MainMenu : public mia::UI, public mia::Observer
{
public:
    MainMenu();
    ~MainMenu();

private:
    mia::Image *_image;

    mia::rect rect00;
    mia::rect rect01;
    mia::rect rect02;

public:
    void Activate();
    void DeActivate();

    void Update(int message) override;
};