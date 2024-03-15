#include "engine-components.hpp"

mia::Generic      &mia::generic   = mia::Generic::Instance();
mia::SDLHandle    &mia::sdlHandle = mia::SDLHandle::Instance();
mia::TimeManager  &mia::time      = mia::TimeManager::Instance();
mia::Camera       &mia::camera    = mia::Camera::Instance();
mia::InputManager &mia::input     = mia::InputManager::Instance();
mia::EventManager &mia::event     = mia::EventManager::Instance();
mia::Renderer     &mia::renderer  = mia::Renderer::Instance();
mia::PhysicsWorld &mia::physics   = mia::PhysicsWorld::Instance();
mia::DebugManager &mia::debug     = mia::DebugManager::Instance();