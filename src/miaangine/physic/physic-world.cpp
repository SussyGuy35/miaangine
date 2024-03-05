#include "physic-world.hpp"

namespace mia
{
    PhysicWorld::PhysicWorld():
        _gravity(Vector2(0.0, 9.81))
    {}

    void PhysicWorld::AddBody(Body *body)
    {
        _bodies.push_back(body);
    }

    bool PhysicWorld::GetBody(int index, Body *bodyRef)
    {
        if (index >= static_cast<int>(_bodies.size())) return false;

        bodyRef = _bodies[index];
        return true;
    }

    void PhysicWorld::Step(double timePass) //TODO
    {
        BodiesVelocityCalculate(timePass);
        
        BodiesCollideCheck();
    }

    bool PhysicWorld::IsColliding(Body *bodyA, Body *bodyB)
    {
        float aMinX = bodyA->master->position.x + bodyA->offset.x - bodyA->size.x; 
        float aMaxX = bodyA->master->position.x + bodyA->offset.x + bodyA->size.x; 
        float aMinY = bodyA->master->position.y + bodyA->offset.y - bodyA->size.y; 
        float aMaxY = bodyA->master->position.y + bodyA->offset.y + bodyA->size.y; 

        float bMinX = bodyB->master->position.x + bodyB->offset.x - bodyB->size.x; 
        float bMaxX = bodyB->master->position.x + bodyB->offset.x + bodyB->size.x; 
        float bMinY = bodyB->master->position.y + bodyB->offset.y - bodyB->size.y; 
        float bMaxY = bodyB->master->position.y + bodyB->offset.y + bodyB->size.y; 

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

            position += body->velocity * timePass;
        }
    }

    void PhysicWorld::BodiesCollideCheck()
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