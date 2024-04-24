#pragma once

#include "miaangine.hpp"

class UIMain : public mia::UI
{
public:
    UIMain();
    ~UIMain();

private:
    mia::Image *_image;

public:
    void Activate();
    void DeActivate();
};