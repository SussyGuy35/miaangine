#include "physics.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Physics::Physics()
    {}

    Physics::~Physics()
    {}
#pragma endregion

#pragma region Public method
    void Physics::RegisterBody(Body *body)
    {
        _bodies.push_back(body);
    }

    void Physics::RemoveBody(Body *body)
    {
        auto bodyIterator = std::find(_bodies.begin(), _bodies.end(), body);

        if (bodyIterator != _bodies.end())
        {
            _bodies.erase(bodyIterator);
        }
    }

    void Physics::Update(double elapsedTime)
    {
        BodiesDynamicsHandle(elapsedTime);
    }
#pragma endregion

#pragma region Private method
    void Physics::BodiesDynamicsHandle(double elapsedTime)
    {
        for (Body *body : _bodies)
        {
            printf("%f\n", body->velocity().magnitude());

            body->velocity() += body->force() / body->mass();

            body->master()->position() += body->velocity() * elapsedTime;

            body->force() = v2f::zero();
        }
    }
#pragma endregion
}