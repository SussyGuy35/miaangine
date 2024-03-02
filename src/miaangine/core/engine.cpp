#include "engine.hpp"

mia::SDLHandle *mia::sdlHandle = new mia::SDLHandle(800, 600, false);
mia::EventManager *mia::eventManager = new mia::EventManager();
mia::InputManager *mia::inputManager = new mia::InputManager();
mia::PortraitRenderer *mia::portraitRenderer = new mia::PortraitRenderer();
mia::PhysicWorld *mia::physicWorld = new mia::PhysicWorld();

void mia::Init()
{
    SDL_Log("*MIAANGINE*");

    sdlHandle->Init();

    inputManager->SetupKeyBind();
}

void mia::End()
{
    sdlHandle->Clear();

    delete(sdlHandle);
    delete(eventManager);
    delete(inputManager);
    delete(portraitRenderer);
    delete(physicWorld);
}

void mia::NewFrame()
{
    eventManager->onEnterNewFrame->NotifyListeners();

    Time::Step();
    inputManager->Update();

    eventManager->mainFrameLoop->NotifyListeners();

    physicWorld->Step(0.0); //TODO
}

void mia::Render()
{
    mia::portraitRenderer->RenderPotraits();
}