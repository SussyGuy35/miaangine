#ifndef _MIA_EVENT_MANAGER_HPP
#define _MIA_EVENT_MANAGER_HPP

#include <memory> //FIXME

#include "util/singleton.hpp"

#include "regular-event-publisher.hpp"

namespace mia
{
    class EventManager : public Singleton<EventManager>
    {
    private:
        friend class Singleton<EventManager>;
        EventManager();
        ~EventManager();

    public:
        std::unique_ptr<RegularEventPublisher> onEnterNewFrame;
        std::unique_ptr<RegularEventPublisher> primaryUpdate;
    };
}

#endif