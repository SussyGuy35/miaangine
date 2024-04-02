#include "physics-world.hpp"

namespace mia
{
#pragma region Constructor Destructor
    PhysicsWorld::PhysicsWorld()
    {}

    PhysicsWorld::~PhysicsWorld()
    {}
#pragma endregion

#pragma region Public method
    void PhysicsWorld::RegisterBody(Body *body)
    {
        _bodies.push_back(body);
    }

    void PhysicsWorld::RemoveBody(Body *body)
    {
        auto listenerIterator = std::find(_bodies.begin(), _bodies.end(), body);

        if (listenerIterator != _bodies.end())
        {
            _bodies.erase(listenerIterator);
        }
    }

    void PhysicsWorld::Step(double elapsedTime)
    {
        BodiesDynamicsHandle(elapsedTime);
    }
#pragma endregion

#pragma region Private method
    void PhysicsWorld::BodiesDynamicsHandle(double elapsedTime)
    {
        for (Body *body : _bodies)
        {
            body->velocity() += body->force() / body->mass();

            body->master()->position() += body->velocity() * elapsedTime;

            body->force() = v2f::zero();
        }
    }
#pragma endregion
}