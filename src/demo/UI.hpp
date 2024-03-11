#pragma once

#include "miaangine.hpp"

class SImage : public mia::ScreenObject
{
public:
    SImage();

    void Update(uint8_t message) override;
};