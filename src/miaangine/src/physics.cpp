#include "physics.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Physics::Physics():
        _bodiesList(std::vector<Body*>())
    {}

    Physics::~Physics()
    {}
#pragma endregion

#pragma region Public method
    void Physics::RegisterBody(Body *body)
    {
        _bodiesList.push_back(body);
    }

    void Physics::UnregisterBody(Body *body)
    {
        auto bodyIterator = std::find(_bodiesList.begin(), _bodiesList.end(), body);

        if (bodyIterator != _bodiesList.end())
        {
            _bodiesList.erase(bodyIterator);
        }
    }

    void Physics::Update(double elapsedTime)
    {
        BodiesDynamicsHandle(elapsedTime);
        BodiesCollisionHandle();
    }

    std::vector<Body*> Physics::GetColliding(Body *body)
    {
        
    }

    void Physics::ResolveCollision(Body *lbody, Body *rbody)
    {
        
    }
#pragma endregion

#pragma region Private method
    void Physics::BodiesDynamicsHandle(double elapsedTime)
    {
        for (Body *body : _bodiesList)
        {
            body->velocity() += body->force() / body->mass();

            body->master().position() += body->velocity() * elapsedTime;

            body->force() = v2f::zero();
        }
    }

    void Physics::BodiesCollisionHandle()
    {
        for (Body* body : _bodiesList)
        {
            if (body->getType() == _BODY_STATIC) continue;

            for (Body* other : _bodiesList)
            {
                if (body->getType() == _BODY_TRIGGER) continue;

                if (body->GetRect().overlap(other->GetRect()))
                {
                    if (body->getType() == _BODY_DYNAMIC)
                    {
                        ResolveCollision(body, other);
                    }
                    else 
                    {
                        // TODO TRIGGER collision
                    }
                }
            }
        }
    }
#pragma endregion
}