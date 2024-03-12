#include "UI.hpp"

SImage::SImage():
    ScreenObject("UI", 0, 0)

{
    MakeImage(20, 50, 0, 0);
    mia::renderer->imageHandle->RegisterImage(image());

    mia::event->primaryUpdate->RegisterListener(this);
}

void SImage::Update(uint8_t message)
{
    switch (message)
    {
    case mia::_EVENT_PRIMARY_UPDATE:
        position.x += .02;
        break;
    
    default:
        break;
    }
}