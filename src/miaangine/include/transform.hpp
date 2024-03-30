#ifndef _MIA_TRANSFORM_HPP
#define _MIA_TRANSFORM_HPP

#include "object.hpp"

namespace mia
{
    class Transform : public Object
    {
    #pragma region Contructor Destructor
    protected:
        Transform(const char *name = "unnamed", mia::v2f position = mia::v2f::zero(), float scale = 1, Transform* parent = nullptr);
    public:
        virtual ~Transform();
    #pragma endregion

    #pragma region Attribute
    private:
        mia::v2f _position;
        float _scale;
        Transform *_parent;
    #pragma endregion

    #pragma region Get-method
    public:
        mia::v2f position() const;
        mia::v2f localPosition() const;
        float scale() const;
        const Transform* parent() const; 
    #pragma endregion

    #pragma region Set-method
    public:
        mia::v2f& position();
        mia::v2f SetLocalPosition(mia::v2f newPosition);
        float& scale();
        Transform* parent();
    #pragma endregion

    #pragma region Public method
    public:
        virtual mia::v2f GetScreenPosition() const = 0;
    #pragma endregion
    
    #pragma region Inherited method
        const char* ToStr() const override;
    #pragma endregion;
    };
}

#endif