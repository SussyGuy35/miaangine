#ifndef _MIA_TRANSFORM_HPP
#define _MIA_TRANSFORM_HPP

#include "object.hpp"

namespace mia
{
    class Transform : public Object
    {
    protected:
    #pragma region Contructor Destructor
        Transform(); //TODO constructor
        virtual ~Transform();
    #pragma endregion

    private:
    #pragma region Attribute
        mia::v2f _localPos;
        float _scale;
    #pragma endregion

    public:
    #pragma region Get-method
        mia::v2f localPosition() const;
        mia::v2f globalPosition() const;
        float scale() const;
    #pragma endregion

    #pragma region Set-method
        mia::v2f& localPosition();
        mia::v2f& globalPosition();
        float& scale();
    #pragma endregion

    #pragma region Public method
        virtual mia::v2f GetScreenPosition() const;
    #pragma endregion
    };
}

#endif