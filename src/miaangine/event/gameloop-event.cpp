#include "gameloop-event.hpp"

#include <algorithm>

namespace mia 
{
    GameloopEvent::GameloopEvent()
    {

    }

    void GameloopEvent::RegisterListener(IEventListener* listener)
    {
        _listeners.push_back(listener);
    }

    void GameloopEvent::RemoveListener(IEventListener* listener)
    {
        auto listenerIterator = std::find(_listeners.begin(), _listeners.end(), listener);

        if (listenerIterator != _listeners.end())
        {
            _listeners.erase(listenerIterator);
        }
    }

    void GameloopEvent::NotifyListeners()
    {
        for (IEventListener* listener : _listeners)
        {
            listener->Update();
        }
    }
}