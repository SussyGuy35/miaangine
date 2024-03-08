#ifndef _MIA_ENGINE_HPP
#define _MIA_ENGINE_HPP

#include "sdl-handle.hpp"
#include "input/input-manager.hpp"
#include "event/event-manager.hpp"
#include "graphic/portrait-renderer.hpp"
#include "physics/physics-world.hpp"

namespace mia
{
    extern SDLHandle *sdlHandle;
    extern InputManager *input;
    extern EventManager *event;
    extern PortraitRenderer *portraitRenderer;
    extern PhysicsWorld *physics;

    void Init(uint32_t width, uint32_t height, bool fullscreen);
    void End();

    void NewFrame();
    void Render();
}

#endif