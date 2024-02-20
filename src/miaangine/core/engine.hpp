#ifndef _MIA_ENGINE_HPP
#define _MIA_ENGINE_HPP

#include "event/event-manager.hpp"
#include "input/input-manager.hpp"
#include "core/sdl-handle.hpp"

namespace mia
{
    extern SDLHandle *sdlHandle;
    extern EventManager *eventManager;
    extern InputManager *inputManager;

    void Init();
    void End();

    void RegisterInput();
    void NextFrame();
}

#endif