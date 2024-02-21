#ifndef _MIA_GAME_LOOP_EVENTS_HPP
#define _MIA_GAME_LOOP_EVENTS_HPP

#include <stdint.h>
#include <vector>

#include "event-publisher-interface.hpp"

namespace mia 
{
    class GameLoopEventPublisher : public IEventPublisher
    {
    public:
        GameLoopEventPublisher(uint8_t message = 0):
            _message(message)
        {}

    private:
        std::vector<IEventListener *> _listeners; 

        uint8_t _message;

    public:
        void RegisterListener(IEventListener *listener) override;
        void RemoveListener(IEventListener *listener) override;
        void NotifyListeners() override;
    };
}

#endif