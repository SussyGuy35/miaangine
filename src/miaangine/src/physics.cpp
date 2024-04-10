#include "physics.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Physics::Physics():
        _bodiesList(std::vector<Body*>())
    {}

    Physics::~Physics()
    {}
#pragma endregion

#pragma region Public method
    void Physics::RegisterBody(Body *body)
    {
        _bodiesList.push_back(body);
    }

    void Physics::UnregisterBody(Body *body)
    {
        auto bodyIterator = std::find(_bodiesList.begin(), _bodiesList.end(), body);

        if (bodyIterator != _bodiesList.end())
        {
            _bodiesList.erase(bodyIterator);
        }
    }

    const std::vector<Body*> Physics::GetBodiesList()
    {
        return _bodiesList;
    }

    void Physics::Update(double elapsedTime)
    {
        for (Body *body : _bodiesList)
        {
            if (body->getType() == _BODY_STATIC) continue;

            // Force
            body->velocity() += body->force() / body->mass();
            body->force() = v2f::zero();

            // Dynamic
            if (body->getType() == _BODY_DYNAMIC)
            {
                double time = elapsedTime;
                BodiesDynamicsHandle(body, time, 0);
            }

            // Trigger
            if (body->getType() == _BODY_TRIGGER)
            {
                for (Body* other : _bodiesList)
                {
                    if (body == other || body->getType() == _BODY_STATIC) continue;
                    if (body->GetRect().overlap(other->GetRect()))
                    {
                        // TODO TRIGGER
                    }
                }
            }
        }
    }
#pragma endregion

#pragma region Private method
    void Physics::BodiesDynamicsHandle(Body *body, double &remainTime, int index)
    {
        int collisionFaces = 0;
        for (int i = 0; i < MAX_COLLISION_RESOLUTION; i++)
        {
            double updateTime = remainTime;

            for (Body* other : _bodiesList)
            {
                if (body == other) continue;

                double collisionTime = 0;
                QueryCollisionResolusion(body, other, collisionTime, collisionFaces);
                updateTime = std::min(updateTime, collisionTime);
            }

            printf("%d %d %d %d\n", ((collisionFaces >> 1) & 1),((collisionFaces >> 2) & 1),((collisionFaces >> 3) & 1),((collisionFaces >> 4) & 1));
            
            if ( ((collisionFaces >> 2) & 1) || ((collisionFaces >> 4) & 1) ) body->velocity().x = 0;
            if ( ((collisionFaces >> 1) & 1) || ((collisionFaces >> 3) & 1) ) body->velocity().y = 0;

            body->master().position() += body->velocity() * updateTime;

            remainTime -= updateTime;
            if (remainTime <= 0) break;
        }
    }

    void Physics::QueryCollisionResolusion(Body *body, Body *other, double &collisionTime, int &collisionFaces)
    {
        rect lrect = body->GetRect();
        rect rrect = other->GetRect();

        if (body->velocity().x == 0 && body->velocity().y == 0) 
        {
            collisionTime = std::numeric_limits<double>::infinity();
            return;
        }
        else if (body->velocity().x == 0)
        {
            if (
                lrect.pos.x + lrect.siz.x <= rrect.pos.x ||
                lrect.pos.x               >= rrect.pos.x + rrect.siz.x
            )
            {
                collisionTime = std::numeric_limits<double>::infinity();
                return;
            }

            float dyEnter, tyEnter;
            if (body->velocity().y > 0)
                dyEnter =  rrect.pos.y                - (lrect.pos.y + lrect.siz.y);
            else 
                dyEnter = (rrect.pos.y + rrect.siz.y) -  lrect.pos.y;

            tyEnter = dyEnter / body->velocity().y;

            if (tyEnter < 0) 
            {
                collisionTime = std::numeric_limits<double>::infinity();
            }
            else 
            {
                collisionTime = tyEnter;
                if (tyEnter == 0)
                {
                    collisionFaces |= (body->velocity().y > 0 ? (1 << 1) : (1 << 3));
                }
            }
        }
        else if (body->velocity().y == 0)
        {
            if (
                lrect.pos.y + lrect.siz.y <= rrect.pos.y ||
                lrect.pos.y               >= rrect.pos.y + rrect.siz.y
            )
            {
                collisionTime = std::numeric_limits<double>::infinity();
                return;
            }

            float dxEnter, txEnter;
            if (body->velocity().x > 0)
                dxEnter =  rrect.pos.x                - (lrect.pos.x + lrect.siz.x);
            else 
                dxEnter = (rrect.pos.x + rrect.siz.x) -  lrect.pos.x;

            txEnter = dxEnter / body->velocity().x;

            if (txEnter < 0) 
            {
                collisionTime = std::numeric_limits<double>::infinity();
            }
            else 
            {
                collisionTime = txEnter;
                if (txEnter == 0)
                {
                    collisionFaces |= (body->velocity().x > 0 ? (1 << 2) : (1 << 4));
                }
            }
        }
        else 
        {
            float dxEnter, dxExit;
            float dyEnter, dyExit;

            if (body->velocity().x > 0)
            {
                dxEnter =  rrect.pos.x                - (lrect.pos.x + lrect.siz.x);
                dxExit  = (rrect.pos.x + rrect.siz.x) -  lrect.pos.x;
            }
            else 
            {
                dxEnter = (rrect.pos.x + rrect.siz.x) -  lrect.pos.x;
                dxExit  =  rrect.pos.x                - (lrect.pos.x + lrect.siz.x);
            }

            if (body->velocity().y > 0)
            {
                dyEnter =  rrect.pos.y                - (lrect.pos.y + lrect.siz.y);
                dyExit  = (rrect.pos.y + rrect.siz.y) -  lrect.pos.y;
            }
            else 
            {
                dyEnter = (rrect.pos.y + rrect.siz.y) -  lrect.pos.y;
                dyExit  =  rrect.pos.y                - (lrect.pos.y + lrect.siz.y);
            }

            float txEnter = dxEnter / body->velocity().x;
            float tyEnter = dyEnter / body->velocity().y;
            float txExit  = dxExit  / body->velocity().x;
            float tyExit  = dyExit  / body->velocity().y;
            float enterTime = std::max(txEnter, tyEnter);
            float exitTime  = std::min(txExit , tyExit );

            if (enterTime >= exitTime || enterTime < 0) 
            {
                collisionTime = std::numeric_limits<double>::infinity();
            }
            else 
            {
                collisionTime = enterTime;
                if (enterTime <= 0)
                {
                    if (txEnter == 0)
                    {
                        collisionFaces |= (body->velocity().x > 0 ? (1 << 2) : (1 << 4));
                    }
                    if (tyEnter == 0)
                    {
                        collisionFaces |= (body->velocity().y > 0 ? (1 << 1) : (1 << 3));
                    }
                }
            }
        }
    }
#pragma endregion
}