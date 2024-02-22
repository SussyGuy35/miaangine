#ifndef _MIA_ENGINE_HPP
#define _MIA_ENGINE_HPP

#include "event/event-manager.hpp"
#include "input/input-manager.hpp"
#include "core/sdl-handle.hpp"
#include "graphic/portrait-renderer.hpp"

namespace mia
{
    extern SDLHandle *sdlHandle;
    extern EventManager *eventManager;
    extern InputManager *inputManager;
    extern PortraitRenderer *portraitRenderer;

    void Init();
    void End();

    void NewFrame();
    void Render();
}

#endif