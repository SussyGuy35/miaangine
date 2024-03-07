#include "physic-world.hpp"

namespace mia
{
    PhysicWorld::PhysicWorld():
        _gravity(Vector2(0.0, 9.81))
    {}

    void PhysicWorld::RegisterBody(Body *body)
    {
        _bodies.push_back(body);
    }

    void PhysicWorld::Step(double timePass)
    {
        BodiesVelocityCalculate(timePass);
        
        BodiesCollideCheck();
    }

    bool PhysicWorld::IsColliding(Body *bodyA, Body *bodyB)
    {
        float aMinX = bodyA->position->x + bodyA->offset.x; 
        float aMaxX = bodyA->position->x + bodyA->offset.x + bodyA->size.x; 
        float aMinY = bodyA->position->y + bodyA->offset.y; 
        float aMaxY = bodyA->position->y + bodyA->offset.y - bodyA->size.y; 

        float bMinX = bodyB->position->x + bodyB->offset.x; 
        float bMaxX = bodyB->position->x + bodyB->offset.x + bodyB->size.x; 
        float bMinY = bodyB->position->y + bodyB->offset.y; 
        float bMaxY = bodyB->position->y + bodyB->offset.y - bodyB->size.y; 

        return (aMinX <= bMaxX &&
                aMaxX >= bMinX &&
                aMinY <= bMaxY &&
                aMaxY >= bMinY);
    }

    void PhysicWorld::BodiesVelocityCalculate(double timePass)
    {
        for (int i = 0; i < static_cast<int>(_bodies.size()); i++)
        {
            Body *body = _bodies[i];
            Vector2 &position = body->master->position;

            position.x += body->velocity.x * timePass;
            position.y += body->velocity.y * timePass;
        }
    }

    void PhysicWorld::BodiesCollideCheck() //TODO
    {
        for (int i = 0; i < static_cast<int>(_bodies.size()); i++) _bodies[i]->colliding = false;
        for (int i = 0; i < static_cast<int>(_bodies.size()); i++)
        {
            Body *bodyA = _bodies[i];
            bodyA->Log();
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