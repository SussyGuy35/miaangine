#ifndef _MIA_WORLD_OBJECT_HPP
#define _MIA_WORLD_OBJECT_HPP

#include "transform.hpp"

namespace mia
{
    class WorldObject : public Transform
    {
    #pragma region Contructor Destructor
    public:
        WorldObject(); //TODO constructor
        ~WorldObject();
    #pragma endregion

    #pragma region Attribute
    private:
    #pragma endregion

    #pragma region Inherited method
    public:
        mia::v2f GetScreenPosition() const override;
    #pragma endregion
    };
}

#endif