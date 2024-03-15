#ifndef _MIA_ENGINE_COMPONENTS_HPP
#define _MIA_ENGINE_COMPONENTS_HPP

#include "generic-task.hpp"
#include "sdl-handle.hpp"
#include "time/time-manager.hpp"
#include "camera.hpp"
#include "input/input-manager.hpp"
#include "event/event-manager.hpp"
#include "graphic/renderer.hpp"
#include "physics/physics-world.hpp"
#include "debug/debug-manager.hpp"

namespace mia
{
    extern GenericTask      &generic;
    extern SDLHandle    &sdl;
    extern TimeManager  &time;
    extern Camera       &camera;
    extern InputManager &input;
    extern EventManager &event;
    extern Renderer     &renderer;
    extern PhysicsWorld &physics;
    extern DebugManager &debug;
}

#endif