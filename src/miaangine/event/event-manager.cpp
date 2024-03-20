#include "event-manager.hpp"

namespace mia
{
    EventManager::EventManager():
        _onEnterNewFrame(*new RegularEventPublisher(_EVENT_ON_ENTER_FRAME)),
        _primaryUpdate(*new RegularEventPublisher(_EVENT_PRIMARY_UPDATE))
    {}

    EventManager::~EventManager()
    {}

    RegularEventPublisher& EventManager::onEnterNewFrame()
    {
        return _onEnterNewFrame;
    }
    RegularEventPublisher& EventManager::primaryUpdate()
    {
        return _primaryUpdate;
    }
}