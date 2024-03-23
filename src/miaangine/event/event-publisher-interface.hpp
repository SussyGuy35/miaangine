#ifndef _MIA_EVENT_PUBLISHER_INTERFACE_HPP
#define _MIA_EVENT_PUBLISHER_INTERFACE_HPP

#include "event-listener.hpp"

namespace mia
{
    class IEventPublisher
    {
    public:
        virtual ~IEventPublisher() {}

        virtual void RegisterListener(EventListener *listener) = 0;
        virtual void RemoveListener(EventListener *listener) = 0;
        virtual void NotifyListeners() = 0;
    };
}

#endif