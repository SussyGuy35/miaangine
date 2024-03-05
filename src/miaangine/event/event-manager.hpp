#ifndef _MIA_EVENT_MANAGER_HPP
#define _MIA_EVENT_MANAGER_HPP

#include <memory>

#include "regular-event-publisher.hpp"

namespace mia
{
    class EventManager
    {
    public:
        EventManager():
            onEnterNewFrame(std::make_unique<RegularEventPublisher>(1)),
            mainFrameStepLoop(std::make_unique<RegularEventPublisher>(2))
        {}

    public:
        std::unique_ptr<RegularEventPublisher> onEnterNewFrame;
        std::unique_ptr<RegularEventPublisher> mainFrameStepLoop;
    };
}

#endif