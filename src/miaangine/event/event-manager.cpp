#include "event-manager.hpp"

namespace mia
{
    EventManager::EventManager():
        onEnterNewFrame(*new RegularEventPublisher(_EVENT_ON_ENTER_FRAME)),
        primaryUpdate(*new RegularEventPublisher(_EVENT_PRIMARY_UPDATE))
    {}

    EventManager::~EventManager()
    {}
}