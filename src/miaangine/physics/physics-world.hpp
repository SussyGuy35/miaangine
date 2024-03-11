#ifndef _MIA_PHYSIC_WORLD_HPP
#define _MIA_PHYSIC_WORLD_HPP

#include <vector>

#include "body.hpp"

namespace mia
{
    class PhysicsWorld
    {
    private:
        static PhysicsWorld *__instance;
    public:
        static PhysicsWorld* Instance() 
        {
            if (!__instance) __instance = new PhysicsWorld(); 
            return __instance;
        }

        PhysicsWorld(const PhysicsWorld&) = delete;
        void operator=(const PhysicsWorld&) = delete;

    private:
        PhysicsWorld();

    public:
        ~PhysicsWorld();

    private:
        std::vector<Body*> _bodies;

        vector2 _gravity;

    public:
        void RegisterBody(Body *body);
        void RemoveBody(Body *body);

        void Step(double timePass);

        bool IsColliding(Body *bodyA, Body *bodyB);
    
    private:
        void BodiesVelocityCalculate(double timePass);
        void BodiesCollideCheck();
    };
}

#endif