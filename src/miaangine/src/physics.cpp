#include "physics.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Physics::Physics():
        _dynamicBodies(std::vector<Body*>()),
        _getBox([](Body* p) { return p->getRect(); }),
        _bodyTree(quadtree::Quadtree<Body*, decltype(_getBox)>({-300, -300, 600, 600}, _getBox)) //FIXME
    {}

    Physics::~Physics()
    {}
#pragma endregion

#pragma region Public method
    void Physics::RegisterBody(Body *body)
    {
        if (!body->isStatic()) _dynamicBodies.push_back(body);

        _bodyTree.add(body);
    }

    void Physics::RemoveBody(Body *body)
    {
        auto bodyIterator = std::find(_dynamicBodies.begin(), _dynamicBodies.end(), body);

        if (bodyIterator != _dynamicBodies.end())
        {
            _dynamicBodies.erase(bodyIterator);
        }

        _bodyTree.remove(body);
    }

    void Physics::Update(double elapsedTime)
    {
        BodiesDynamicsHandle(elapsedTime);
        BodiesCollisionHandle();
    }

    std::vector<Body*> Physics::GetColliding(Body *body)
    {
        return _bodyTree.query(body->getRect());
    }

    void Physics::ResolveCollision(Body *lbody, Body *rbody)
    {

    }
#pragma endregion

#pragma region Private method
    void Physics::BodiesDynamicsHandle(double elapsedTime)
    {
        for (Body *body : _dynamicBodies)
        {
            body->velocity() += body->force() / body->mass();

            body->master()->position() += body->velocity() * elapsedTime;

            body->force() = v2f::zero();
        }
    }

    void Physics::BodiesCollisionHandle()
    {
        for (Body* body : _dynamicBodies)
        {
            std::vector<Body*> others = _bodyTree.query(body->getRect());
            if (others.empty()) continue;

            for (int i = 0; i < COLLISION_RESOLVE_TRY; i++)
            {
                ResolveCollision(body, others.back());

                others = _bodyTree.query(body->getRect());
                if (others.empty()) break;
            }
        }

        // std::vector<std::pair<Body*, Body*>> _bodiesIntersections = _bodyTree.findAllIntersections();
        // for (std::pair<Body*, Body*> bodiesPair : _bodiesIntersections)
        // {
        //     Body* lbody = bodiesPair.first;
        //     Body* rbody = bodiesPair.second;

        //     ResolveCollision(lbody, rbody);
        // }
    }
#pragma endregion
}