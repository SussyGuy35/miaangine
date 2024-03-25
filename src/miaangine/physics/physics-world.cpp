#include "physics-world.hpp"

#include <algorithm>

#include "core/engine-components.hpp"
#include "miaangine-global-constant.hpp"

namespace mia
{
    #pragma region Constructor_Destructor
    PhysicsWorld::PhysicsWorld():
        _gravity(Vector2<>(0.0, 9.81))
    {}

    PhysicsWorld::~PhysicsWorld()
    {}
    #pragma endregion

    #pragma region Public methods
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
        CollisionDetectionHandle();
    }
    #pragma endregion

    #pragma region Private methods
    void PhysicsWorld::BodiesDynamicsHandle(double elapsedTime)
    {
        for (Body *body : _bodies)
        {
            body->velocity() += body->force() / body->mass();

            body->master().position() += body->velocity() * elapsedTime;

            body->force() = Vector2<>::zero();
        }
    }
    void PhysicsWorld::CollisionDetectionHandle()
    {
        
    }
    #pragma endregion
}