#pragma once

#include "miaangine.hpp"

class UIMain : public mia::UI
{
public:
    UIMain();
    ~UIMain();

    mia::Image *_image;
};