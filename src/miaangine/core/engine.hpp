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
    extern std::unique_ptr<SDLHandle>    sdlHandle;
    extern std::unique_ptr<TimeManager>  time;
    extern std::unique_ptr<InputManager> input;
    extern std::unique_ptr<EventManager> event;
    extern std::unique_ptr<Renderer>     renderer;
    extern std::unique_ptr<PhysicsWorld> physics;
    extern std::unique_ptr<DebugManager> debug;

    extern int windowWidth, windowHeight;
    extern bool fullscreenMode; //TODO

    void Init(uint32_t width, uint32_t height, bool fullscreen);
    void End();

    void NewFrame();
    void Render();
}

#endif