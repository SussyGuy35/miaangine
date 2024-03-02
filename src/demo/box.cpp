#include "box.hpp"

void Box::Update(uint8_t message)
{
    switch (message)
    {
    case 2:
        if (fall) position.y += 500 * mia::Time::elapseTime;
        break;
    
    default:
        break;
    }
}