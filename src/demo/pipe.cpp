#include "pipe.hpp"

void Pipe::Update(uint8_t message)
{
    switch (message)
    {
    case 2:
        body->velocity.x = -50;
        break;
    
    default:
        break;
    }
}