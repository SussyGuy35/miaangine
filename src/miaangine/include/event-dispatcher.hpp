#ifndef _MIA_EVENT_DISPATCHER_HPP
#define _MIA_EVENT_DISPATCHER_HPP

#include "common.hpp"

#include "observer.hpp"

namespace mia
{
    enum EventType
    {
        _EVENT_START_GAME = -INT16_MIN,
        _EVENT_ON_ENTER_FRAME,
        _EVENT_PRIMARY_UPDATE,
        _EVENT_AFTER_PHYSICS_CALCULATION
        // TODO
    };

    class EventDispatcher : public Singleton<EventDispatcher>
    {
    private:
        friend class Singleton<EventDispatcher>;
        EventDispatcher();
        ~EventDispatcher();

    private:
        std::vector<Observer*> _observers;

    public:
        void RegisterObserver(Observer *observer);
        void RemoveObserver(Observer *observer);
        void Notify(int message);
    };
}

#endif