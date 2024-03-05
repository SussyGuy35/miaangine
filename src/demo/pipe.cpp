#include "pipe.hpp"

Pipe::Pipe(float x, float y):
    WorldObject(x, y)
{
    MakePortrait(50, 50);
    MakeBody(50, 50);

    mia::portraitRenderer->RegisterPortrait(portrait());

    mia::events->primaryUpdate->RegisterListener(this);
}

void Pipe::Update(uint8_t message)
{
    switch (message)
    {
    case mia::_EVENT_PRIMARY_UPDATE:
        break;
    
    default:
        break;
    }
}