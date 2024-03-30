#include "component.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Component::Component():
        _active(true),
        _master(nullptr)
    {}

    Component::~Component()
    {}
#pragma endregion

#pragma region GetSet method
    bool Component::isActive() const
    {
        return _active;
    }
    const Object* Component::master() const
    {
        return _master;
    }

    bool Component::SetActive(bool newState)
    {
        _active = newState;
    }
    Object* Component::SetMaster(Object* newMaster)
    {
        _master = newMaster;
    }
#pragma endregion

#pragma region Inherited method
    const char* Component::ToStr() const
    {
        return "Component";
    }
#pragma endregion
}