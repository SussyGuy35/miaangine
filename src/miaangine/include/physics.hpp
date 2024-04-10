#ifndef _MIA_PHYSICS_WORLD_HPP
#define _MIA_PHYSICS_WORLD_HPP

#include "common.hpp"

#include "body.hpp"

namespace mia
{
    class Physics : public Singleton<Physics>
    {
    private:
        friend class Singleton<Physics>;
        Physics();
        ~Physics();

    private:
        std::vector<Body*> _bodiesList;

    public:
        void RegisterBody(Body *body);
        void UnregisterBody(Body *body);

        void Update(double elapsedTime);

        std::vector<Body*> GetColliding(Body &body);
        void ResolveCollision(Body &lbody, Body &rbody);

    private:
        void BodiesDynamicsHandle(double elapsedTime);
        void BodiesCollisionHandle();
    };
}

#endif