#ifndef _MIA_ENGINE_HPP
#define _MIA_ENGINE_HPP

#include "input/input-manager.hpp"
#include "sdl-handle.hpp" 
#include "event/event-manager.hpp"
#include "timer.hpp"
#include "graphic/portrait-renderer.hpp"

namespace mia
{
    extern SDLHandle *sdlHandle;
    extern EventManager *eventManager;
    extern InputManager *inputManager;
    extern Timer *timer;
    extern PortraitRenderer *portraitRenderer;

    void Init();
    void End();

    void NewFrame();
    void Render();
}

#endif