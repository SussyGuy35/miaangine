#ifndef _MIA_PHYSIC_WORLD_HPP
#define _MIA_PHYSIC_WORLD_HPP

#include <vector>

#include "util/singleton.hpp"

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