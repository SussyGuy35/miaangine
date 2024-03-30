#ifndef _MIA_WORLD_OBJECT_HPP
#define _MIA_WORLD_OBJECT_HPP

#include "transform.hpp"

namespace mia
{
    class WorldObject : public Transform
    {
    public:
    #pragma region Contructor Destructor
        WorldObject(); //TODO constructor
        ~WorldObject();
    #pragma endregion

    private:
    #pragma region Attribute
        mia::v2f _localPos;
        float _scale;
    #pragma endregion

    public:
    #pragma region Inherited method
        mia::v2f GetScreenPosition() const override;
    #pragma endregion
    };
}

#endif