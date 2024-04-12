#pragma once

#include "miaangine.hpp"

class IPlayerState
{
public:
    virtual ~IPlayerState();
    virtual void InputHandle(int directionInput, bool jumpInput) = 0;
    virtual void Update(mia::Body& body) = 0;
};