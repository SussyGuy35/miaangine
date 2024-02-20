#ifndef _MIA_EVENT_MANAGER_HPP
#define _MIA_EVENT_MANAGER_HPP

#include <memory>

#include "game-loop-event.hpp"

namespace mia
{
    class EventManager
    {
    public:
        EventManager():
            onEnterFrame(std::make_unique<GameLoopEvent>())
        {}

    public:
        std::unique_ptr<GameLoopEvent> onEnterFrame;

    };
}

#endif