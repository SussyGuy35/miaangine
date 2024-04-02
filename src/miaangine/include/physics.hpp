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
        std::vector<Body*> _bodies;

    public:
        void RegisterBody(Body *body);
        void RemoveBody(Body *body);

        void Update(double elapsedTime);

    private:
        void BodiesDynamicsHandle(double elapsedTime);
    };
}

#endif