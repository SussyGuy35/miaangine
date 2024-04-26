#pragma once

#include "miaangine.hpp"

class StartM : public mia::UI, public mia::Observer
{
public:
    StartM();
    ~StartM();

private:
    mia::Image *_image;

public:
    void Update(int message) override;
};