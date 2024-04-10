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

        const int MAX_COLLISION_RESOLUTION = 3;

    public:
        void RegisterBody(Body *body);
        void UnregisterBody(Body *body);

        void Update(double elapsedTime);

        const std::vector<Body*> GetBodiesList();

    private:
        void ApplyForceToBody(Body *body);
        void StaticBodyHandle(Body *body, double elapsedTime);
        void DynamicBodyHandle(Body *body, double elapsedTime);
        void TriggerBodyHandle(Body *body, double elapsedTime);

        double QueryCollisionTimeResolution(Body *body, Body *other, double maxResTime);
        int QueryCollisionTouchResolution(Body *body, Body *other);

        inline bool IsIn(float x, float l, float r);
    };
}

#endif