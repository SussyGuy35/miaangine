#ifndef _MIA_PHYSICS_WORLD_HPP
#define _MIA_PHYSICS_WORLD_HPP

#include "util/singleton.hpp"

#include <vector>

#include "component/body.hpp"

namespace mia
{
    class PhysicWorld : public Singleton<PhysicWorld>
    {
    private:
        friend class Singleton<PhysicsWorld>;
        PhysicsWorld();
        ~PhysicsWorld();

    private:
        std::vector<Body*> _bodies;

        Vector2 _gravity;

    public:
        void RegisterBody(Body *body);
        void RemoveBody(Body *body);

        void Step(double elapsedTime);
    
    private:
        void BodiesDynamicsHandle(double elapsedTime);
    };
}

#endif