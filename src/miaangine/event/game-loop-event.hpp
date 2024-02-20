#ifndef _MIA_GAME_LOOP_EVENTS_HPP
#define _MIA_GAME_LOOP_EVENTS_HPP

#include <vector>

#include "event-publisher-interface.hpp"

namespace mia 
{
    class GameLoopEvent : public IEventPublisher
    {
    public:
        GameLoopEvent();

    private:
        std::vector<IEventListener*> _listeners; 

    public:
        void RegisterListener(IEventListener *listener) override;
        void RemoveListener(IEventListener *listener) override;
        void NotifyListeners() override;
    };
}

#endif