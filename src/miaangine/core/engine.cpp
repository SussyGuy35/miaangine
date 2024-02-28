#include "engine.hpp"

mia::SDLHandle *mia::sdlHandle = new mia::SDLHandle(800, 600, false);
mia::DebugManager *mia::debugManager = new mia::DebugManager();
mia::EventManager *mia::eventManager = new mia::EventManager();
mia::InputManager *mia::inputManager = new mia::InputManager();
mia::Timer *mia::timer = new mia::Timer();
mia::PortraitRenderer *mia::portraitRenderer = new mia::PortraitRenderer();
mia::PhysicWorld *mia::physicWorld = new mia::PhysicWorld();

void mia::Init()
{
    sdlHandle->Init();
    debugManager->Init();

    inputManager->SetupKeyBind();
}

void mia::End()
{
    sdlHandle->Clear();

    delete(sdlHandle);
    delete(debugManager);
    delete(eventManager);
    delete(inputManager);
    delete(timer);
    delete(portraitRenderer);
    delete(physicWorld);
}

void mia::NewFrame()
{
    eventManager->onEnterNewFrame->NotifyListeners();

    timer->Step();
    inputManager->Update();

    eventManager->mainFrameLoop->NotifyListeners();

    physicWorld->Step(0.0); //TODO
}

void mia::Render()
{
    mia::portraitRenderer->RenderPotraits();
}