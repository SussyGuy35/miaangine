#include "game-loop-event.hpp"

#include <algorithm>

namespace mia 
{
    GameLoopEvent::GameLoopEvent()
    {

    }

    void GameLoopEvent::RegisterListener(IEventListener *listener)
    {
        _listeners.push_back(listener);
    }

    void GameLoopEvent::RemoveListener(IEventListener *listener)
    {
        auto listenerIterator = std::find(_listeners.begin(), _listeners.end(), listener);

        if (listenerIterator != _listeners.end())
        {
            _listeners.erase(listenerIterator);
        }
    }

    void GameLoopEvent::NotifyListeners()
    {
        for (IEventListener *listener : _listeners)
        {
            listener->Update();
        }
    }
}