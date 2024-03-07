#include "pipe.hpp"

Pipe::Pipe():
    WorldObject("Pipe", 0, 0),
    PIPE_HOLE_RADIUS(97),
    PIPE_WIDTH(90),
    SPEED(170)

{
    moving = true;

    MakePortrait(PIPE_WIDTH, 600, 0, -600 - PIPE_HOLE_RADIUS);
    MakePortrait(PIPE_WIDTH, 600, 0, PIPE_HOLE_RADIUS);
    portrait(0)->color = {10, 10, 255, 255};
    portrait(1)->color = {10, 10, 255, 255};
    mia::portraitRenderer->RegisterPortrait(portrait(0));
    mia::portraitRenderer->RegisterPortrait(portrait(1));

    MakeBody(PIPE_WIDTH, 600, 0, -600 - PIPE_HOLE_RADIUS);
    MakeBody(PIPE_WIDTH, 600, 0, PIPE_HOLE_RADIUS);
    mia::physicWorld->RegisterBody(body(0));
    mia::physicWorld->RegisterBody(body(1));

    mia::events->primaryUpdate->RegisterListener(this);
}

void Pipe::Update(uint8_t message)
{
    switch (message)
    {
    case mia::_EVENT_PRIMARY_UPDATE:
        if (moving) body()->velocity.x = -SPEED;
        else body()->velocity.x = 0;
        break;
    
    default:
        break;
    }
}

void Pipe::Reset()
{
    int spawnBoundMin = 40 + PIPE_HOLE_RADIUS;
    int spawnBoundMax = 600 - 40 - PIPE_HOLE_RADIUS;
    int spawnPos = rand() % (spawnBoundMax - spawnBoundMin + 1) + spawnBoundMin;

    position.x = 400;
    position.y = spawnPos;
}