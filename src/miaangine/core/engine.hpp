#ifndef _MIA_ENGINE_HPP
#define _MIA_ENGINE_HPP

#include "input/input-manager.hpp"
#include "sdl-handle.hpp"
#include "debug/debug-manager.hpp"
#include "event/event-manager.hpp"
#include "timer.hpp"
#include "graphic/portrait-renderer.hpp"
#include "physic/physic-world.hpp"

namespace mia
{
    extern SDLHandle *sdlHandle;
    extern DebugManager *debugManager;
    extern EventManager *eventManager;
    extern InputManager *inputManager;
    extern Timer *timer;
    extern PortraitRenderer *portraitRenderer;
    extern PhysicWorld *physicWorld;

    void Init();
    void End();

    void NewFrame();
    void Render();
}

#endif