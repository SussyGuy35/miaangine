#ifndef _MIA_EVENT_MANAGER_HPP
#define _MIA_EVENT_MANAGER_HPP

#include <memory>

#include "game-loop-event-publisher.hpp"

namespace mia
{
    class EventManager
    {
    public:
        EventManager():
            onEnterNewFrame(std::make_unique<GameLoopEventPublisher>(1)),
            mainFrameLoop(std::make_unique<GameLoopEventPublisher>(2))
        {}

    public:
        std::unique_ptr<GameLoopEventPublisher> onEnterNewFrame;
        std::unique_ptr<GameLoopEventPublisher> mainFrameLoop;
    };
}

#endif