#include "box.hpp"

Box::Box(float x, float y):
    WorldObject(x, y)
{
    MakePortrait(50, 50);
    MakeBody(50, 50);

    mia::portraitRenderer->RegisterPortrait(portrait());

    mia::events->primaryUpdate->RegisterListener(this);
}

void Box::Update(uint8_t message)
{
    switch (message)
    {
    case mia::_EVENT_PRIMARY_UPDATE:
        if (fall) body()->velocity.y = 500;
        break;
    
    default:
        break;
    }
}