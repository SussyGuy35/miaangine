#include "engine.hpp"

mia::SDLHandle *mia::sdlHandle = new mia::SDLHandle(800, 600, false);
mia::EventManager *mia::eventManager = new mia::EventManager();
mia::InputManager *mia::inputManager = new mia::InputManager();
mia::Timer *mia::timer = new mia::Timer();
mia::PortraitRenderer *mia::portraitRenderer = new mia::PortraitRenderer();

void mia::Init()
{
    sdlHandle->Init();

    inputManager->SetupKeyBind();
}

void mia::End()
{
    sdlHandle->Clear();

    delete(sdlHandle);
    delete(eventManager);
    delete(inputManager);
    delete(timer);
    delete(portraitRenderer);
}

void mia::NewFrame()
{
    eventManager->onEnterNewFrame->NotifyListeners();

    timer->TimerCalculate();
    inputManager->RegisterInput();

    eventManager->mainFrameLoop->NotifyListeners();
}

void mia::Render()
{
    mia::portraitRenderer->RenderPotraits();
}