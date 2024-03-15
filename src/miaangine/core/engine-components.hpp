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
    extern Generic      &generic;
    extern SDLHandle    &sdlHandle;
    extern TimeManager  &time;
    extern Camera       &camera;
    extern InputManager &input;
    extern EventManager &event;
    extern Renderer     &renderer;
    extern PhysicsWorld &physics;
    extern DebugManager &debug;
}

#endif

// mia::Generic      &mia::generic   = mia::Generic::Instance();
// mia::SDLHandle    &mia::sdlHandle = mia::SDLHandle::Instance();
// mia::TimeManager  &mia::time      = mia::TimeManager::Instance();
// mia::Camera       &mia::camera    = mia::Camera::Instance();
// mia::InputManager &mia::input     = mia::InputManager::Instance();
// mia::EventManager &mia::event     = mia::EventManager::Instance();
// mia::Renderer     &mia::renderer  = mia::Renderer::Instance();
// mia::PhysicsWorld &mia::physics   = mia::PhysicsWorld::Instance();
// mia::DebugManager &mia::debug     = mia::DebugManager::Instance();