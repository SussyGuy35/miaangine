#include "event/event-manager.hpp"
#include "input/input-manager.hpp"
#include "core/sdl-handle.hpp"

#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif

int main(int argc, char* argv[])
{
    mia::SDLHandle* sdlHandle = new mia::SDLHandle(800, 600, false);
    mia::EventManager* eventManager = new mia::EventManager();
    mia::InputManager* inputManager = new mia::InputManager();

    sdlHandle->Init();

    inputManager->SetupKeyBind();

    while (true)
    {
        inputManager->RegisterInput();

        eventManager->onEnterFrame->NotifyListeners();

        if (inputManager->IsQuit()) break;
    }

    sdlHandle->Clear();

    return 0;
}