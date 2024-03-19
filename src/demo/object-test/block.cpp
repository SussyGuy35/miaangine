#include "block.hpp"

#include <math.h>

Block::Block(float x, float y, float speed, float dir, float colorOff):
    WorldObject("Block", x, y),
    SPEED(speed),
    DIR(dir)

{
    MakePortrait(5, 5);
    mia::renderer->portraitHandle->RegisterPortrait(portrait());
    portrait()->color = {10 + colorOff, 30 + colorOff, 0 + colorOff, 255};

    MakeBody(5, 5);
    // mia::physics->RegisterBody(body());

    mia::event->primaryUpdate->RegisterListener(this);

    direction.x = std::cos(DIR);
    direction.y = std::sin(DIR);
}

void Block::Update(uint8_t message)
{
    switch (message)
    {
    case mia::_EVENT_PRIMARY_UPDATE:
        position += direction * SPEED * mia::time->deltaTime;

        if (position.x < 0) 
        {
            position.x = 0;
            direction.x *= -1;
            // body()->velocity.x *= -1;
        }
        if (position.x + 5 > 600)
        {
            position.x = 600 - 5;
            direction.x *= -1;
            // body()->velocity.x *= -1;
        }
        if (position.y < 0) 
        {
            position.y = 0;
            direction.y *= -1;
            // body()->velocity.y *= -1;
        }
        if (position.y + 5 > 600)
        {
            position.y = 600 - 5;
            direction.y *= -1;
            // body()->velocity.y *= -1;
        }
        break;
    
    default:
        break;
    }
}