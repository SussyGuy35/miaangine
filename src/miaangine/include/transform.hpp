#ifndef _MIA_TRANSFORM_HPP
#define _MIA_TRANSFORM_HPP

#include "object.hpp"

namespace mia
{
    class Transform : public Entity
    {
    public:
        Transform(Object* master, v2f position, float scale);
        virtual ~Transform();

    private:
        v2f _position;
        float _scale;
        Object* _master;
        
    public:
        v2f position() const;
        v2f localPosition() const;
        float scale() const;
        const Object* master() const;

        v2f& position();
        v2f SetLocalPosition(v2f newPosition);
        float& scale();
        Object* master();

    public:
        int getID() const override;
        const char* ToStr() const override;
    };
}

#endif