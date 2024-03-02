#ifndef _MIA_ENGINE_HPP
#define _MIA_ENGINE_HPP

#include "input/input-manager.hpp"
#include "sdl-handle.hpp"
#include "event/event-manager.hpp"
#include "graphic/portrait-renderer.hpp"
#include "physic/physic-world.hpp"

namespace mia
{
    extern SDLHandle *sdlHandle;
    extern EventManager *eventManager;
    extern InputManager *inputManager;
    extern PortraitRenderer *portraitRenderer;
    extern PhysicWorld *physicWorld;

    void Init();
    void End();

    void NewFrame();
    void Render();
}

#endif