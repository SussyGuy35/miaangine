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

    void PhysicsWorld::Step(double timePass)
    {
        BodiesVelocityCalculate(timePass);
        
        BodiesCollideCheck();
    }

    bool PhysicsWorld::IsColliding(Body *bodyA, Body *bodyB)
    {
        float aMinX = bodyA->position->x + bodyA->offset.x; 
        float aMaxX = bodyA->position->x + bodyA->offset.x + bodyA->size.x; 
        float aMinY = bodyA->position->y + bodyA->offset.y; 
        float aMaxY = bodyA->position->y + bodyA->offset.y + bodyA->size.y; 

        float bMinX = bodyB->position->x + bodyB->offset.x; 
        float bMaxX = bodyB->position->x + bodyB->offset.x + bodyB->size.x; 
        float bMinY = bodyB->position->y + bodyB->offset.y; 
        float bMaxY = bodyB->position->y + bodyB->offset.y + bodyB->size.y; 

        return (aMinX <= bMaxX &&
                aMaxX >= bMinX &&
                aMinY <= bMaxY &&
                aMaxY >= bMinY);
    }

    void PhysicsWorld::BodiesVelocityCalculate(double timePass)
    {
        for (int i = 0; i < static_cast<int>(_bodies.size()); i++)
        {
            Body *body = _bodies[i];
            vector2 &position = body->master()->position;

            position.x += body->velocity.x * timePass;
            position.y += body->velocity.y * timePass;
        }
    }

    void PhysicsWorld::BodiesCollideCheck() //FIXME
    {
        for (int i = 0; i < static_cast<int>(_bodies.size()); i++) _bodies[i]->colliding = false;
        for (int i = 0; i < static_cast<int>(_bodies.size()); i++)
        {
            Body *bodyA = _bodies[i];
            for (int j = i + 1; j < static_cast<int>(_bodies.size()); j++)
            {
                Body *bodyB = _bodies[j];

                if (IsColliding(bodyA, bodyB))
                {
                    bodyA->colliding = bodyB->colliding = true;
                }
            }
        }
    }
}