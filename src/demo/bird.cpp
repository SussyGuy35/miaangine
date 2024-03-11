#include "bird.hpp"

Bird::Bird():
    WorldObject("Bird", 70, 320),
    SIZE(mia::Vector2(50, 47)),
    GRAVITY(-1500),
    JUMP_VELOCITY(550)
{
    MakePortrait(SIZE);
    mia::renderer->portraitHandle->RegisterPortrait(portrait());
    portrait()->color = {255, 20, 255, 255};

    MakeBody(SIZE);
    mia::physics->RegisterBody(body());

    mia::event->primaryUpdate->RegisterListener(this);
}

void Bird::Update(uint8_t message)
{
    switch (message)
    {
    case mia::_EVENT_PRIMARY_UPDATE:
        body()->velocity.y += GRAVITY * mia::time->elapseTime;
        
        if (mia::input->GetButtonDown("Jump"))
        {
            body()->velocity.y = JUMP_VELOCITY;
        }

        if (body()->colliding) 
        {
            portrait()->color = {255, 0, 0, 255};
        }
        else 
        {
            portrait()->color = {255, 20, 255, 255};
        }

        break;
    
    default:
        break;
    }
}