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

        const int MAX_COLLISION_RESOLUTION_TIME = 1;
        const int MAX_COLLISION_RESOLUTION_SEARCH = 128;

    public:
        void RegisterBody(Body *body);
        void UnregisterBody(Body *body);

        void Update(double elapsedTime);

        const std::vector<Body*> GetBodiesList();

    private:
        void ApplyForceToBody(Body *body);
    };
}

#endif