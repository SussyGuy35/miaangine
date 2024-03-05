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
            onEnterNewFrame(std::make_unique<RegularEventPublisher>(_EVENT_ON_ENTER_FRAME)),
            primaryUpdate(std::make_unique<RegularEventPublisher>(_EVENT_PRIMARY_UPDATE))
        {}

    public:
        std::unique_ptr<RegularEventPublisher> onEnterNewFrame;
        std::unique_ptr<RegularEventPublisher> primaryUpdate;
    };
}

#endif