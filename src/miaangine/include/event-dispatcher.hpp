#ifndef _MIA_EVENT_DISPATCHER_HPP
#define _MIA_EVENT_DISPATCHER_HPP

#include "common.hpp"

#include "observer.hpp"

namespace mia
{
    enum EventType
    {
        _EVENT_ON_ENTER_FRAME = -INT16_MIN,
        _EVENT_PRIMARY_UPDATE
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