#pragma once

#include "miaangine.hpp"

class Box : public mia::Object
{
public:
    Box(float x, float y, float sx, float sy);
    ~Box();

    mia::Body *_body;
};