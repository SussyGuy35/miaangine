#include "world-object.hpp"

#include "component.hpp"

namespace mia
{
#pragma region Contructor Destructor
    WorldObject::WorldObject(const char *name, mia::v2f position, float scale, Transform* parent):
        Transform(name, position, scale, parent)
    {}

    WorldObject::~WorldObject()
    {
        for (Component *component : _components) delete component;
        _components.clear();
    }
#pragma endregion

#pragma region Inherited method
    // mia::v2f WorldObject::GetScreenPosition() const
    // {
    //     //TODO
    // }

    const char* WorldObject::ToStr() const
    {
        return mia::string("WorldObject");
    }
#pragma endregion
}