#pragma once

#include "miaangine.hpp"

class MainMenu : public mia::UI, public mia::Observer
{
public:
    MainMenu();
    ~MainMenu();

private:
    mia::Image *_image;

public:
    void Activate();
    void DeActivate();

    void Update(int message) override;
};