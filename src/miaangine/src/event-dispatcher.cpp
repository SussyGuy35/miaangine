#include "event-dispatcher.hpp"

namespace mia
{
#pragma region Constructor Destructor
    EventDispatcher::EventDispatcher()
    {}

    EventDispatcher::~EventDispatcher()
    {}
#pragma endregion

#pragma region Public method
    void EventDispatcher::RegisterObserver(Observer *observer)
    {
        _observers.push_back(observer);
    }

    void EventDispatcher::RemoveObserver(Observer *observer)
    {
        auto observerIterator = std::find(_observers.begin(), _observers.end(), observer);

        if (observerIterator != _observers.end())
        {
            _observers.erase(observerIterator);
        }
    }

    void EventDispatcher::Notify(int message)
    {
        for (Observer *observer : _observers)
        {
            observer->Update(message);
        }
    }
#pragma endregion
}