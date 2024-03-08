#include "regular-event-publisher.hpp"

#include <algorithm>

#include "time/time-manager.hpp"

namespace mia 
{
    void RegularEventPublisher::RegisterListener(IEventListener *listener)
    {
        _listeners.push_back(listener);
    }

    void RegularEventPublisher::RemoveListener(IEventListener *listener)
    {
        auto listenerIterator = std::find(_listeners.begin(), _listeners.end(), listener);

        if (listenerIterator != _listeners.end())
        {
            _listeners.erase(listenerIterator);
        }
    }

    void RegularEventPublisher::NotifyListeners()
    {
        for (IEventListener *listener : _listeners)
        {
            listener->Update(_message);
        }
    }

    void RegularEventPublisher::Log() //TODO
    {
        SDL_Log("%.2f - %llu | "
                "EventListener > Listeners Count(%d)",
                TimeManager::time, TimeManager::stepCount,
                _listeners.size());
    }
}