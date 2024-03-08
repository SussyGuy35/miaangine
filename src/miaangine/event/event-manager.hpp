#ifndef _MIA_EVENT_MANAGER_HPP
#define _MIA_EVENT_MANAGER_HPP

#include <memory>

#include "regular-event-publisher.hpp"

namespace mia
{
    class EventManager
    {
    private:
        static EventManager *__instance;
    public:
        static EventManager* Instance() 
        {
            if (!__instance) __instance = new EventManager(); 
            return __instance;
        }

        EventManager(const EventManager&) = delete;
        void operator=(const EventManager&) = delete;

    private:
        EventManager();
        
    public:
        ~EventManager();

    public:
        std::unique_ptr<RegularEventPublisher> onEnterNewFrame;
        std::unique_ptr<RegularEventPublisher> primaryUpdate;
    };
}

#endif