#ifndef _MIA_EVENT_MANAGER_HPP
#define _MIA_EVENT_MANAGER_HPP

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
        RegularEventPublisher &onEnterNewFrame;
        RegularEventPublisher &primaryUpdate;
    };
}

#endif