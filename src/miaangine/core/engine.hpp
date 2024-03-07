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
    extern Events *events;
    extern PortraitRenderer *portraitRenderer;
    extern PhysicWorld *physicWorld;

    void Init(uint32_t width, uint32_t height, bool fullscreen);
    void End();

    void NewFrame();
    void Render();
}

#endif