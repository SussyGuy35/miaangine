#ifndef _MIA_PHYSICS_WORLD_HPP
#define _MIA_PHYSICS_WORLD_HPP

#include "common.hpp"

#include "body.hpp"
#include "tilemap.hpp"

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
        std::vector<Tilemap*> _tilemapsList;
        std::vector<rect> _staticRectList;

    public:
        void RegisterBody(Body *body);
        void UnregisterBody(Body *body);

        void RegisterTilemap(Tilemap *tilemap);
        void UnregisterTilemap(Tilemap *tilemap);

        void Update(double elapsedTime);

        const std::vector<Body*> GetBodiesList();

        bool Query(rect rect);
        bool Query(float x, float y, float sx, float sy);

        bool RaycastRect(const v2f &origin, const v2f &velocity, const rect &target, float &timeHit, v2f &hit, v2f &normal);
        bool BodycastRect(Body *body, const rect &otherRect, const v2f &step, float &timeHit, v2f &hit, v2f &normal);

    private:
        void ApplyForceToBody(Body *body);
        void ApplyBodyDynamic(Body *body, double elapsedTime);
        void BodyCollisionResolution(Body *body, const rect &otherRect, double elapsedTime);
    };
}

#endif