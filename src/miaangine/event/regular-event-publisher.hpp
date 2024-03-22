#ifndef _MIA_REGULAR_EVENT_PUBLISHER_HPP
#define _MIA_REGULAR_EVENT_PUBLISHER_HPP

#include <vector>

#include "interface/event-publisher-interface.hpp"

namespace mia 
{
    class RegularEventPublisher : public IEventPublisher
    {
    private:
        friend class EventManager;
        RegularEventPublisher(unsigned char message = 0);
        ~RegularEventPublisher();

    private:
        std::vector<IEventListener*> _listeners; 

        unsigned char _message;

    public:
        // Abstract Method
        void RegisterListener(IEventListener *listener) override;
        void RemoveListener(IEventListener *listener) override;
        void NotifyListeners() override;
    };
}

#endif