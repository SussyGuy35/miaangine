#ifndef _MIA_EVENT_PUBLISHER_INTERFACE_HPP
#define _MIA_EVENT_PUBLISHER_INTERFACE_HPP

#include "event-listener-interface.hpp"

#include "core/time.hpp"

namespace mia
{
    class IEventPublisher
    {
    public:
        virtual void RegisterListener(IEventListener *listener) = 0;
        virtual void RemoveListener(IEventListener *listener) = 0;
        virtual void NotifyListeners() = 0;
        virtual void Log() = 0;
    };
}

#endif