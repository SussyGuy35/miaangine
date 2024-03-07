#include "bird.hpp"

Bird::Bird(float x, float y):
    WorldObject("Bird", x, y),
    SIZE(mia::Vector2(50, 47)),
    GRAVITY(1500),
    JUMP_VELOCITY(-550)

{
    MakePortrait(SIZE);
    MakeBody(SIZE);

    mia::portraitRenderer->RegisterPortrait(portrait());
    portrait()->color = {255, 20, 255, 255};

    mia::events->primaryUpdate->RegisterListener(this);
}

void Bird::Update(uint8_t message)
{
    switch (message)
    {
    case mia::_EVENT_PRIMARY_UPDATE:
        body()->velocity.y += GRAVITY * mia::Time::elapseTime;
        
        if (mia::inputs->GetButtonDown("Jump"))
        {
            body()->velocity.y = JUMP_VELOCITY;
        }

        break;
    
    default:
        break;
    }
}