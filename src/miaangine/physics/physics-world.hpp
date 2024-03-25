#ifndef _MIA_PHYSICS_WORLD_HPP
#define _MIA_PHYSICS_WORLD_HPP

#include "util/singleton.hpp"

#include <vector>

#include "component/body.hpp"
#include "component/collider.hpp"

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

        Vector2<> _gravity; //TODO

    public:

        void RegisterBody(Body *body);
        void RemoveBody(Body *body);

        void RegisterCollider(Collider *collider);
        void RemoveCollider(Collider *collider);

        void Step(double elapsedTime);
    
    private:
        void BodiesDynamicsHandle(double elapsedTime);
        void CollisionDetectionHandle();
    };
}

#endif