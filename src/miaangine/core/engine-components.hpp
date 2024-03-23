#ifndef _MIA_ENGINE_COMPONENTS_HPP
#define _MIA_ENGINE_COMPONENTS_HPP

#include "generic-task.hpp"
#include "input/input-manager.hpp"
#include "time-manager.hpp"
#include "event/event-manager.hpp"
#include "debug/debug-manager.hpp"
#include "graphic/renderer.hpp"
#include "camera.hpp"

#include "miaangine-global-constant.hpp"

namespace mia
{
    inline GenericTask&  generic() { return GenericTask::Instance(); }
    inline InputManager& input()   { return InputManager::Instance(); }
    inline TimeManager&  time()    { return TimeManager::Instance(); }
    inline EventManager& event()   { return EventManager::Instance(); }
    inline DebugManager& debug()   { return DebugManager::Instance(); }
    inline Renderer&     render()  { return Renderer::Instance(); }
    inline Camera&       camera()  { return Camera::Instance(); }
}

#endif