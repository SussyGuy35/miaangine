#ifndef _MIA_EVENT_MANAGER_HPP
#define _MIA_EVENT_MANAGER_HPP

#include <memory>

#include "gameloop-event.hpp"

namespace mia
{
    class EventManager
    {
    public:
        EventManager():
            onEnterFrame(std::make_unique<GameloopEvent>())
        {}

    public:
        std::unique_ptr<GameloopEvent> onEnterFrame;

    };
}

#endif