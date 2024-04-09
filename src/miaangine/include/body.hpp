#ifndef _MIA_BODY_HPP
#define _MIA_BODY_HPP
#include "component.hpp"

#include "Quadtree/Box.h"

namespace mia
{
    enum BodyType
    {
        _BODY_STATIC = 0,
        _BODY_DYNAMIC = 1
    };

    class Body : public Component
    {
    public:
        Body(BodyType type = _BODY_DYNAMIC, v2f size = v2f::one(), v2f offset = v2f::zero(), float mass = 1, v2f initForce = v2f::zero());
        virtual ~Body();

    private:
        int _type;
        v2f _size;
        v2f _offset;
        v2f _pivot;
        bool _trigger;
        float _mass;
        v2f _velocity;
        v2f _force;

    public:
        bool isStatic() const;
        v2f offset() const;
        v2f size() const;
        v2f pivot() const;
        bool isTrigger() const;
        float mass() const;
        v2f velocity() const;
        v2f force() const;
        quadtree::Box<float> getRect() const;

        int& setType(bool newState);
        v2f& offset();
        v2f& size();
        v2f& pivot();
        bool& setTrigger(int newState);
        float& mass();
        v2f& velocity();
        v2f& force();

        v2f AddForce(v2f force);
        v2f AddForce(float x, float y);
        v2f AddAcceleration(v2f acceleration);
        v2f AddAcceleration(float x, float y);

    public:
        int getID() const override;
        const char* ToStr() const override;
        bool Init() override;
    };
}

#endif