#include "engine.hpp"

mia::SDLHandle *mia::sdlHandle = new mia::SDLHandle(800, 600, false);
mia::EventManager *mia::eventManager = new mia::EventManager();
mia::InputManager *mia::inputManager = new mia::InputManager();

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
}

void mia::RegisterInput()
{
    inputManager->RegisterInput();
}

void mia::NextFrame()
{
    eventManager->onEnterFrame->NotifyListeners();
}