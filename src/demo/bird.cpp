#include "bird.hpp"

Bird::Bird():
    WorldObject("Bird", 70, 320),
    SIZE(mia::Vector2(50, 47)),
    GRAVITY(-1500),
    JUMP_VELOCITY(550)

{
    MakePortrait(SIZE);
    mia::portraitRenderer->RegisterPortrait(portrait());
    portrait()->color = {255, 20, 255, 255};

    MakeBody(SIZE);
    mia::physicWorld->RegisterBody(body());

    mia::events->primaryUpdate->RegisterListener(this);
}

void Bird::Update(uint8_t message)
{
    switch (message)
    {
    case mia::_EVENT_PRIMARY_UPDATE:
        body()->velocity.y += GRAVITY * mia::Time::elapseTime;
        
        if (mia::Input::GetButtonDown("Jump"))
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