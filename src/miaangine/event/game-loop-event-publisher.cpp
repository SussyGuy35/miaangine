#include "game-loop-event-publisher.hpp"

#include <algorithm>

namespace mia 
{
    void GameLoopEventPublisher::RegisterListener(IEventListener *listener)
    {
        _listeners.push_back(listener);
    }

    void GameLoopEventPublisher::RemoveListener(IEventListener *listener)
    {
        auto listenerIterator = std::find(_listeners.begin(), _listeners.end(), listener);

        if (listenerIterator != _listeners.end())
        {
            _listeners.erase(listenerIterator);
        }
    }

    void GameLoopEventPublisher::NotifyListeners()
    {
        for (IEventListener *listener : _listeners)
        {
            listener->Update(_message);
        }
    }

    void GameLoopEventPublisher::Log()
    {
        SDL_Log("(%lf | %ld)\nEventListener > Listeners count: %ld", Time::time, Time::frameCount, _listeners.size());
    }
}