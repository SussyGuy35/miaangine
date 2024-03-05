#include "box.hpp"

void Box::Update(uint8_t message)
{
    switch (message)
    {
    case 2:
        if (fall) body->velocity.y = 500;
        break;
    
    default:
        break;
    }
}