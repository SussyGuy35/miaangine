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
    extern Generic      &generic   = mia::Generic::Instance();
    extern SDLHandle    &sdlHandle = mia::SDLHandle::Instance();
    extern TimeManager  &time      = mia::TimeManager::Instance();
    extern Camera       &camera    = mia::Camera::Instance();
    extern InputManager &input     = mia::InputManager::Instance();
    extern EventManager &event     = mia::EventManager::Instance();
    extern Renderer     &renderer  = mia::Renderer::Instance();
    extern PhysicsWorld &physics   = mia::PhysicsWorld::Instance();
    extern DebugManager &debug     = mia::DebugManager::Instance();
}

#endif