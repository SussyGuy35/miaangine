#ifndef _MIA_EVENT_MANAGER_HPP
#define _MIA_EVENT_MANAGER_HPP

#include "util/singleton.hpp"

#include "regular-event-publisher.hpp"

namespace mia
{
    typedef enum
    {
        // All events
        _EVENT_ON_ENTER_FRAME,
        _EVENT_PRIMARY_UPDATE

    } EventTypes;

    class EventManager : public Singleton<EventManager>
    {
    private:
        friend class Singleton<EventManager>;
        EventManager();
        ~EventManager();

    private:
        // Events
        RegularEventPublisher &_onEnterNewFrame;
        RegularEventPublisher &_primaryUpdate;
    
    public:
        // Accessing
        inline RegularEventPublisher& onEnterNewFrame();
        inline RegularEventPublisher& primaryUpdate();
    };
}

#endif