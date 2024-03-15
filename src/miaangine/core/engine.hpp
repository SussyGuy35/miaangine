#ifndef _MIA_ENGINE_HPP
#define _MIA_ENGINE_HPP

#include <memory>

#include "sdl-handle.hpp"
#include "time/time-manager.hpp"
#include "input/input-manager.hpp"
#include "event/event-manager.hpp"
#include "graphic/renderer.hpp"
#include "physics/physics-world.hpp"
#include "debug/debug-manager.hpp"

namespace mia
{
    extern SDLHandle    &sdlHandle;
    extern TimeManager  &time;
    extern InputManager &input;
    extern EventManager &event;
    extern Renderer     &renderer;
    extern PhysicsWorld &physics;
    extern DebugManager &debug;

    extern int windowWidth, windowHeight;
    extern bool fullscreenMode;

    void Init(uint32_t width, uint32_t height, bool fullscreen);
    void End();

    void NewFrame();
    void Render();
}

#endif