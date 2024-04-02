#ifndef _MIA_PHYSICS_WORLD_HPP
#define _MIA_PHYSICS_WORLD_HPP

#include "common.hpp"

#include "body.hpp"

namespace mia
{
    class PhysicsWorld : public Singleton<PhysicsWorld>
    {
    private:
        friend class Singleton<PhysicsWorld>;
        PhysicsWorld();
        ~PhysicsWorld();

    private:
        std::vector<Body*> _bodies;

    public:
        void RegisterBody(Body *body);
        void RemoveBody(Body *body);

        void Step(double elapsedTime);

    private:
        void BodiesDynamicsHandle(double elapsedTime);
    };
}

#endif