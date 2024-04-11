#ifndef _MIA_BODY_HPP
#define _MIA_BODY_HPP

#include "object.hpp"

#include "util/rect.hpp"

namespace mia
{
    enum BodyType
    {
        _BODY_STATIC = 0,
        _BODY_DYNAMIC
    };

    class Body : public Entity
    {
    public:
        Body(Object *master, int type = _BODY_DYNAMIC, v2f size = v2f::one(), v2f pivot = v2f::zero(), v2f offset = v2f::zero());
        virtual ~Body();

    private:
        Object *_master;

        int _type;

        v2f _size;
        v2f _pivot;
        v2f _offset;
        bool _triggered;
        
        float _mass;
        v2f _velocity;
        v2f _force;

    public:
        const Object& master() const;
        int getType() const;
        const v2f& size() const;
        const v2f& pivot() const;
        const v2f& offset() const;
        bool IsTriggered() const;
        const float& mass() const;
        const v2f& velocity() const;
        const v2f& force() const;

        Object& master();
        int setType(int newType);
        v2f& size();
        v2f& pivot();
        v2f& offset();
        float& mass();
        v2f& velocity();
        v2f& force();

        Object& ChangeMaster(Object *newMaster);
        
        rect GetRect() const;
        bool SetTriggered(bool newState);

        v2f AddForce(v2f force);
        v2f AddForce(float x, float y);
        v2f AddAcceleration(v2f acceleration);
        v2f AddAcceleration(float x, float y);

    public:
        int getID() const override;
        const char* ToStr() const override;
    };
}

#endif