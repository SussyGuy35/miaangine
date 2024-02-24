#include "box.hpp"

void Box::Update(uint8_t message)
{
    switch (message)
    {
    case 2:
        position.y += .1;
        break;
    
    default:
        break;
    }
}