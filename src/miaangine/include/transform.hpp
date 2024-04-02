#ifndef _MIA_TRANSFORM_HPP
#define _MIA_TRANSFORM_HPP

#include "object.hpp"

namespace mia
{
    class Transform : public Object
    {
    public:
        Transform(const char *name = "unnamed", mia::v2f position = mia::v2f::zero(), float scale = 1, Transform* parent = nullptr);
        virtual ~Transform();

    private:
        mia::v2f _position;
        float _scale;
        Transform *_parent;
        
    public:
        mia::v2f position() const;
        mia::v2f localPosition() const;
        float scale() const;
        const Transform* parent() const; 

    public:
        mia::v2f& position();
        mia::v2f SetLocalPosition(mia::v2f newPosition);
        float& scale();
        Transform* parent();

    public:
        int getID() const override;
        const char* ToStr() const override;
    };
}

#endif