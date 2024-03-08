#include "event-manager.hpp"

namespace mia
{
    EventManager *EventManager::__instance = nullptr;

    EventManager::EventManager():
        onEnterNewFrame(std::make_unique<RegularEventPublisher>(_EVENT_ON_ENTER_FRAME)),
        primaryUpdate(std::make_unique<RegularEventPublisher>(_EVENT_PRIMARY_UPDATE))
    {}

    EventManager::~EventManager()
    {
        __instance = nullptr;
    }
}