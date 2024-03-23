#ifndef _MIA_REGULAR_EVENT_PUBLISHER_HPP
#define _MIA_REGULAR_EVENT_PUBLISHER_HPP

#include <vector>

#include "event-publisher-interface.hpp"

namespace mia 
{
    class RegularEventPublisher : public IEventPublisher
    {
    private:
        friend class EventManager;
        RegularEventPublisher(unsigned char message = 0);
        ~RegularEventPublisher();

    private:
        std::vector<EventListener*> _listeners; 

        unsigned char _message;

    public:
        // Abstract Method
        void RegisterListener(EventListener *listener) override;
        void RemoveListener(EventListener *listener) override;
        void NotifyListeners() override;
    };
}

#endif