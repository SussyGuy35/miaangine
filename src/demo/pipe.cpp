#include "pipe.hpp"

void Pipe::Update(uint8_t message)
{
    switch (message)
    {
    case 2:
        position.x -= 50 * mia::Time::elapseTime;
        break;
    
    default:
        break;
    }
}