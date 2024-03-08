#ifndef _MIA_REGULAR_EVENT_PUBLISHER_HPP
#define _MIA_REGULAR_EVENT_PUBLISHER_HPP

#include <stdint.h>
#include <vector>

#include "event-publisher-interface.hpp"

namespace mia 
{
    class RegularEventPublisher : public IEventPublisher
    {
    public:
        RegularEventPublisher(uint8_t message = 0);

        ~RegularEventPublisher();

    private:
        std::vector<IEventListener*> _listeners; 

        uint8_t _message;

    public:
        void RegisterListener(IEventListener *listener) override;
        void RemoveListener(IEventListener *listener) override;
        void NotifyListeners() override;
    };

    typedef enum
    {
        _EVENT_ON_ENTER_FRAME,
        _EVENT_PRIMARY_UPDATE

    } RegularEventType;
}

#endif