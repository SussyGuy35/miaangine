#include "world-object.hpp"

namespace mia
{
#pragma region Contructor Destructor
    WorldObject::WorldObject(const char *name, mia::v2f position, float scale):
        Transform(name, position, scale)
    {}

    WorldObject::~WorldObject()
    {}
#pragma endregion

#pragma region Inherited method
    mia::v2f WorldObject::GetScreenPosition() const
    {
        //TODO
    }

    const char* WorldObject::ToStr() const
    {
        return mia::string("WorldObject");
    }
#pragma endregion
}