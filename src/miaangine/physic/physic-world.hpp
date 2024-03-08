#ifndef _MIA_PHYSIC_WORLD_HPP
#define _MIA_PHYSIC_WORLD_HPP

#include <vector>

#include "body.hpp"

namespace mia
{
    class PhysicWorld
    {
    private:
        static PhysicWorld *__instance;
    public:
        static PhysicWorld* Instance() 
        {
            if (!__instance) __instance = new PhysicWorld(); 
            return __instance;
        }

        PhysicWorld(const PhysicWorld&) = delete;
        void operator=(const PhysicWorld&) = delete;

    private:
        PhysicWorld();

    private:
        std::vector<Body*> _bodies;

        Vector2 _gravity;

    public:
        void RegisterBody(Body *body);
        // void RemoveBody(Body *body); //TODO

        void Step(double timePass);

        bool IsColliding(Body *bodyA, Body *bodyB);
    
    private:
        void BodiesVelocityCalculate(double timePass);
        void BodiesCollideCheck();
    };
}

#endif