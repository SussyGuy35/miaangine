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
        void DynamicBodyHandle(double elapsedTime);
        void DynamicBodyDynamicUpdate(Body* body, double elapsedTime, std::vector<bool> &bodiesQueried, int time = 0);

        double GetTimeToCollideBody(Body *body, rect consideredRect, double maxTime);
        double GetTimeToCollide(const rect& lRect, const rect& rRect, v2f velocity);

        void TouchedBodyHandle(Body *body);
        int GetTouchedFaces(const rect& lRect, const rect& rRect);
    };
}

#endif