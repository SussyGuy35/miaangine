#include "box.hpp"

Box::Box(float x, float y, float sx, float sy):
    WorldObject("Box", x, y)
{
    MakePortrait("bird-00.png", sx, sy);
    portrait().color() = {255, 255, 255, 255};
    MakeBody();

    mia::renderer.RegisterPortrait(&portrait());
    mia::physics.RegisterBody(&body());

    mia::event.primaryUpdate().RegisterListener(this);
}

void Box::Update(uint8_t message)
{
    switch (message)
    {
    case mia::_EVENT_PRIMARY_UPDATE:
        body().AddAcceleration((mia::vector2)mia::vector2::down() * 9.81);
        break;
    
    default:
        break;
    }
}