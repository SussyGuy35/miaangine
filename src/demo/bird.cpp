#include "bird.hpp"

Bird::Bird(float x, float y):
    WorldObject(x, y)
{
    MakePortrait(50, 50);
    MakeBody(50, 50);

    mia::portraitRenderer->RegisterPortrait(portrait());
    portrait()->color = {255, 20, 255, 255};

    mia::events->primaryUpdate->RegisterListener(this);
}

void Bird::Update(uint8_t message)
{
    switch (message)
    {
    case mia::_EVENT_PRIMARY_UPDATE:
        acceleration += GRAVITY * mia::Time::elapseTime;

        body()->velocity.y += acceleration;
        break;
    
    default:
        break;
    }
}