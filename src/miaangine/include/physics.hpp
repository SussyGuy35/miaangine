#ifndef _MIA_PHYSICS_WORLD_HPP
#define _MIA_PHYSICS_WORLD_HPP

#include "common.hpp"

#include <functional>
#include "Quadtree/Quadtree.h"

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
        std::vector<Body*> _dynamicBodies;

        std::function<quadtree::Box<float>(Body* p)> _getBox;
        quadtree::Quadtree<Body*, decltype(_getBox)> _bodyTree;

        const int COLLISION_RESOLVE_TRY = 3;

    public:
        void RegisterBody(Body *body);
        void RemoveBody(Body *body);

        void Update(double elapsedTime);

        std::vector<Body*> GetColliding(Body *body);
        void ResolveCollision(Body *lbody, Body *rbody);

    private:
        void BodiesDynamicsHandle(double elapsedTime);
        void BodiesCollisionHandle();
    };
}

#endif