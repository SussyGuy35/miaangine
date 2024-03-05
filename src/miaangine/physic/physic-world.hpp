#ifndef _MIA_PHYSIC_WORLD_HPP
#define _MIA_PHYSIC_WORLD_HPP

#include <vector>

#include "body.hpp"

namespace mia
{
    class PhysicWorld
    {
    public:
        PhysicWorld();

    private:
        std::vector<Body*> _bodies;

        Vector2 _gravity;

    public:
        void AddBody(Body *body);
        // void RemoveBody(Body *body); //TODO
        bool GetBody(int index, Body *bodyRef);

        void Step(double timePass);

        bool IsColliding(Body *bodyA, Body *bodyB);
    
    private:
        void BodiesVelocityCalculate(double timePass);
        void BodiesCollideCheck();
    };
}

#endif