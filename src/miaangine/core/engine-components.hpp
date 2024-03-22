#ifndef _MIA_ENGINE_COMPONENTS_HPP
#define _MIA_ENGINE_COMPONENTS_HPP

#include "generic-task.hpp"
// #include "sdl-handle.hpp" //TODO
// #include "time/time-manager.hpp"
// #include "camera.hpp"
// #include "input/input-manager.hpp"
// #include "event/event-manager.hpp"
// #include "graphic/renderer.hpp"
// #include "physics/physics-world.hpp"
// #include "debug/debug-manager.hpp"

#include "miaangine-global-constant.hpp"

namespace mia
{
    inline GenericTask& generic() { return GenericTask::Instance(); }
    // extern SDLHandle    &sdl; //TODO
    // extern TimeManager  &time;
    // extern Camera       &camera;
    // extern InputManager &input;
    // extern EventManager &event;
    // extern Renderer     &renderer;
    // extern PhysicsWorld &physics;
    // extern DebugManager &debug;
}

#endif