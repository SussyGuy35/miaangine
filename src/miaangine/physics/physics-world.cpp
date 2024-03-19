#include "physics-world.hpp"

#include "core/engine-components.hpp"

#include <algorithm>

namespace mia
{
    PhysicsWorld::PhysicsWorld():
        _gravity(vector2(0.0, 9.81))
    {}

    PhysicsWorld::~PhysicsWorld()
    {}

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

    bool PhysicsWorld::IsColliding(Body *bodyA, Body *bodyB)
    {
        float aMinX = bodyA->position().x + bodyA->offset().x; 
        float aMaxX = bodyA->position().x + bodyA->offset().x + bodyA->size().x; 
        float aMinY = bodyA->position().y + bodyA->offset().y; 
        float aMaxY = bodyA->position().y + bodyA->offset().y + bodyA->size().y; 

        float bMinX = bodyB->position().x + bodyB->offset().x; 
        float bMaxX = bodyB->position().x + bodyB->offset().x + bodyB->size().x; 
        float bMinY = bodyB->position().y + bodyB->offset().y; 
        float bMaxY = bodyB->position().y + bodyB->offset().y + bodyB->size().y; 

        return (aMinX <= bMaxX &&
                aMaxX >= bMinX &&
                aMinY <= bMaxY &&
                aMaxY >= bMinY);
    }

    void PhysicsWorld::BodiesDynamicsHandle(double elapsedTime)
    {
        for (Body *body : _bodies)
        {
            body->velocity() += body->force() / body->mass() * elapsedTime;
            body->position() += body->velocity() * elapsedTime;

            body->force() = vector2::zero();
        }
    }
}