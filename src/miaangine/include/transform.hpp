#ifndef _MIA_TRANSFORM_HPP
#define _MIA_TRANSFORM_HPP

#include "object.hpp"

namespace mia
{
    class Transform : public Entity
    {
    public:
        Transform(v2f position, v2f scale, Transform *parent, Object *master);
        virtual ~Transform();

    private:
        v2f _position;
        v2f _scale;
        Transform *_parent;
        Object *_master;
        
    public:
        v2f position() const;
        v2f localPosition() const;
        v2f scale() const;
        const Transform& parent() const;
        const Object* master() const;

        v2f& position();
        v2f SetLocalPosition(v2f newPosition);
        v2f& scale();
        Transform& parent();
        Object* master();

    public:
        int getID() const override;
        const char* ToStr() const override;
    };
}

#endif