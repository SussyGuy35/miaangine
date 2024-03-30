#ifndef _MIA_TRANSFORM_HPP
#define _MIA_TRANSFORM_HPP

#include "object.hpp"

namespace mia
{
    class Transform : public Object
    {
    #pragma region Contructor Destructor
    protected:
        Transform(); //TODO constructor
    public:
        virtual ~Transform();
    #pragma endregion

    #pragma region Attribute
    private:
        mia::v2f _localPos;
        float _scale;
    #pragma endregion

    #pragma region Get-method
    public:
        mia::v2f localPosition() const;
        mia::v2f globalPosition() const;
        float scale() const;
    #pragma endregion

    #pragma region Set-method
    public:
        mia::v2f& localPosition();
        mia::v2f& globalPosition();
        float& scale();
    #pragma endregion

    #pragma region Public method
    public:
        virtual mia::v2f GetScreenPosition() const;
    #pragma endregion
    };
}

#endif