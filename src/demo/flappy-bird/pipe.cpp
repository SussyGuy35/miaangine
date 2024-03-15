#include "pipe.hpp"

Pipe::Pipe():
    WorldObject("Pipe", 0, 0),
    PIPE_HOLE_RADIUS(97),
    PIPE_WIDTH(90),
    SPEED(170)

{
    moving = true;

    MakePortrait(PIPE_WIDTH, mia::generic.windowHeight, 0, -mia::generic.windowHeight - PIPE_HOLE_RADIUS);
    MakePortrait(PIPE_WIDTH, mia::generic.windowHeight, 0, PIPE_HOLE_RADIUS);
    portrait(0).color = {10, 10, 255, 255};
    portrait(1).color = {10, 10, 255, 255};
    mia::renderer.portraitHandle.RegisterPortrait(&portrait(0));
    mia::renderer.portraitHandle.RegisterPortrait(&portrait(1));

    MakeBody(PIPE_WIDTH, mia::generic.windowHeight, 0, -mia::generic.windowHeight - PIPE_HOLE_RADIUS);
    MakeBody(PIPE_WIDTH, mia::generic.windowHeight, 0, PIPE_HOLE_RADIUS);
    mia::physics.RegisterBody(&body(0));
    mia::physics.RegisterBody(&body(1));

    mia::event.primaryUpdate.RegisterListener(this);
}

void Pipe::Update(uint8_t message)
{
    switch (message)
    {
    case mia::_EVENT_PRIMARY_UPDATE:
        if (moving) body().velocity.x = -SPEED;
        else body().velocity.x = 0;
        break;
    
    default:
        break;
    }
}

void Pipe::Reset()
{
    int spawnBoundMin = 20 + PIPE_HOLE_RADIUS;
    int spawnBoundMax = mia::generic.windowHeight - 20 - PIPE_HOLE_RADIUS;
    int spawnPos = rand() % (spawnBoundMax - spawnBoundMin + 1) + spawnBoundMin;

    position.x = 400;
    position.y = spawnPos;
}