#include "event-manager.hpp"

namespace mia
{
    #pragma region Constructor_Destructor
    EventManager::EventManager():
        _onEnterNewFrame(*new RegularEventPublisher(_EVENT_ON_ENTER_FRAME)),
        _primaryUpdate(*new RegularEventPublisher(_EVENT_PRIMARY_UPDATE))
    {}

    EventManager::~EventManager()
    {}
    #pragma endregion

    #pragma region Event accessing
    RegularEventPublisher& EventManager::onEnterNewFrame()
    {
        return _onEnterNewFrame;
    }
    RegularEventPublisher& EventManager::primaryUpdate()
    {
        return _primaryUpdate;
    }
    #pragma endregion
}