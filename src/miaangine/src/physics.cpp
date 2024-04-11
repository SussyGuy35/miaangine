#include "physics.hpp"

#include "renderer.hpp"

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
        for (Body *body : _bodiesList) ApplyForceToBody(body);
        
        DynamicBodyHandle(elapsedTime);
    }
#pragma endregion

#pragma region Private method
    void Physics::ApplyForceToBody(Body *body)
    {
        body->velocity() += body->force() / body->mass();
        body->force() = v2f::zero();
    }

    void Physics::DynamicBodyHandle(double elapsedTime)
    {
        for (int i = 0; i < MAX_COLLISION_RESOLUTION_TIME; i++)
        {
            std::vector<bool> bodiesQueried(_bodiesList.size(), false);

            for (size_t i = 0; i < _bodiesList.size(); i++)
            {
                if (bodiesQueried[i]) continue;

                Body *body = _bodiesList[i];
                if (body->getType() != _BODY_DYNAMIC) continue;

                bodiesQueried[i] = true;
                DynamicBodyDynamicUpdate(body, elapsedTime, bodiesQueried);
            }
        }

        // for (int i = 0; i < COLLISION_RESOLUTION_TIME; i++)
        // {
        //     std::vector<double> updateTime(_bodiesList.size(), 0);
        //     for (size_t i = 0; i < _bodiesList.size(); i++)
        //     {
        //         Body *body = _bodiesList[i];
        //         if (body->getType() != _BODY_DYNAMIC) continue;
        //         if (bodiesUpdateTimeLeft[i] <= 0) continue;

        //         rect bodyRect = body->GetRect();
        //         rect consideredRect;
        //         consideredRect.pos.x = std::min(bodyRect.pos.x, bodyRect.pos.x + body->velocity().x * float(elapsedTime));
        //         consideredRect.pos.y = std::min(bodyRect.pos.y, bodyRect.pos.y + body->velocity().y * float(elapsedTime));
        //         consideredRect.siz.x = bodyRect.siz.x + std::abs(body->velocity().x * float(elapsedTime));
        //         consideredRect.siz.y = bodyRect.siz.y + std::abs(body->velocity().y * float(elapsedTime));
            
        //         updateTime[i] = GetTimeToCollideBody(body, consideredRect, bodiesUpdateTimeLeft, bodiesUpdateTimeLeft[i]);
        //     }

        //     for (size_t i = 0; i < _bodiesList.size(); i++)
        //     {
        //         Body *body = _bodiesList[i];
        //         if (body->getType() != _BODY_DYNAMIC) continue;
        //         if (bodiesUpdateTimeLeft[i] <= 0) continue;
                
        //         body->master().position() += body->velocity() * updateTime[i];

        //         bodiesUpdateTimeLeft[i] -= updateTime[i];
        //     }
        // }
    }

    void Physics::DynamicBodyDynamicUpdate(Body* body, double elapsedTime, std::vector<bool> &bodiesQueried, int time)
    {
        if (time == MAX_COLLISION_RESOLUTION_SEARCH) return;

        rect bodyRect = body->GetRect();
        rect consideredRect;
        consideredRect.pos.x = std::min(bodyRect.pos.x, bodyRect.pos.x + body->velocity().x * float(elapsedTime));
        consideredRect.pos.y = std::min(bodyRect.pos.y, bodyRect.pos.y + body->velocity().y * float(elapsedTime));
        consideredRect.siz.x = bodyRect.siz.x + std::abs(body->velocity().x * float(elapsedTime));
        consideredRect.siz.y = bodyRect.siz.y + std::abs(body->velocity().y * float(elapsedTime));

        for (size_t i = 0; i < _bodiesList.size(); i++)
        {
            if (bodiesQueried[i]) continue;

            Body *other = _bodiesList[i];
            if (!consideredRect.overlap(other->GetRect())) continue;

            bodiesQueried[i] = true;
            DynamicBodyDynamicUpdate(other, elapsedTime, bodiesQueried, time);
        // printf("%s : %s | %d %d %d\n", body->master().name().str(), other->master().name().str(), bodiesQueried[0], bodiesQueried[1], bodiesQueried[2]);
        }

        double updateTime = GetTimeToCollideBody(body, consideredRect, elapsedTime);
        body->master().position() += body->velocity() * updateTime;
        // printf("%s : %f\n", body->master().name().str(), updateTime);
    }

    double Physics::GetTimeToCollideBody(Body *body, rect consideredRect, double maxTime)
    {
        double result = maxTime;
        for (size_t i = 0; i < _bodiesList.size(); i++)
        {
            Body *other = _bodiesList[i];
            if (other == body) continue;
            if (!consideredRect.overlap(other->GetRect())) continue;;

            double collideTime = GetTimeToCollide(
                body->GetRect(), 
                other->GetRect(), 
                body->velocity()
            );
            result = std::min(result, collideTime);
        }
        return result;
    }

    double Physics::GetTimeToCollide(const rect& lRect, const rect& rRect, v2f velocity)
    {
        float lxNear, rxNear, lxFar, rxFar;
        float lyNear, ryNear, lyFar, ryFar;

        if (velocity.x > 0) 
        {
            lxNear = lRect.pos.x + lRect.siz.x;
            lxFar  = lRect.pos.x;
            rxNear = rRect.pos.x;
            rxFar  = rRect.pos.x + rRect.siz.x;
        }
        else 
        {
            lxNear = lRect.pos.x;
            lxFar  = lRect.pos.x + lRect.siz.x;
            rxNear = rRect.pos.x + rRect.siz.x;
            rxFar  = rRect.pos.x;
        }

        if (velocity.y > 0) 
        {
            lyNear = lRect.pos.y + lRect.siz.y;
            lyFar  = lRect.pos.y;
            ryNear = rRect.pos.y;
            ryFar  = rRect.pos.y + rRect.siz.y;
        }
        else 
        {
            lyNear = lRect.pos.y;
            lyFar  = lRect.pos.y + lRect.siz.y;
            ryNear = rRect.pos.y + rRect.siz.y;
            ryFar  = rRect.pos.y;
        }

        float dxEnter = rxNear - lxNear;
        float dxExit  = rxFar  - lxFar ;
        float dyEnter = ryNear - lyNear;
        float dyExit  = ryFar  - lyFar ;

        double txEnter, txExit;
        double tyEnter, tyExit;
        
        if (velocity.x == 0)
        {
            txEnter = std::numeric_limits<double>::infinity();
            if (lRect.pos.x < rRect.pos.x + rRect.siz.x && lRect.pos.x + lRect.siz.x > rRect.pos.x) txEnter = -std::numeric_limits<double>::infinity();
            txExit  = std::numeric_limits<double>::infinity();
        }
        else
        {
            txEnter = dxEnter / velocity.x;
            txExit  = dxExit  / velocity.x;
        }

        if (velocity.y == 0)
        {
            tyEnter = std::numeric_limits<double>::infinity();
            if (lRect.pos.y < rRect.pos.y + rRect.siz.y && lRect.pos.y + lRect.siz.y > rRect.pos.y) tyEnter = -std::numeric_limits<double>::infinity();
            tyExit  = std::numeric_limits<double>::infinity();
        }
        else
        {
            tyEnter = dyEnter / velocity.y;
            tyExit  = dyExit  / velocity.y;
        }

        double enterTime = std::max(txEnter, tyEnter);
        double exitTime  = std::min(txExit , tyExit );

        if (enterTime >= exitTime || enterTime < 0) return std::numeric_limits<double>::infinity();
        return enterTime;
    }

    void Physics::TouchedBodyHandle(Body *body)
    {
        rect bodyRect = body->GetRect();
        rect consideredRect;

        consideredRect.pos.x = bodyRect.pos.x - .01;
        consideredRect.pos.y = bodyRect.pos.y - .01;
        consideredRect.siz.x = bodyRect.siz.x + .01;
        consideredRect.siz.y = bodyRect.siz.y + .01;

        int touchedFaces = 0;
        for (Body *other : _bodiesList) // TODO 
        {
            touchedFaces |= GetTouchedFaces(body->GetRect(), other->GetRect());
        }

        if ((touchedFaces >> 1) & 1 && body->velocity().x > 0) body->velocity().x = 0;
        if ((touchedFaces >> 2) & 1 && body->velocity().y > 0) body->velocity().y = 0;
        if ((touchedFaces >> 3) & 1 && body->velocity().x < 0) body->velocity().x = 0;
        if ((touchedFaces >> 4) & 1 && body->velocity().y < 0) body->velocity().y = 0;
    }

    int Physics::GetTouchedFaces(const rect& lRect, const rect& rRect)
    {
        int res = 0;
        
        if (
            lRect.pos.x + lRect.siz.x == rRect.pos.x && 
            lRect.pos.y < rRect.pos.y + rRect.siz.y &&
            lRect.pos.y + lRect.pos.y > rRect.pos.y
        )
            res |= (1 << 1);
        
        if (
            lRect.pos.x == rRect.pos.x + rRect.siz.x && 
            lRect.pos.y < rRect.pos.y + rRect.siz.y &&
            lRect.pos.y + lRect.pos.y > rRect.pos.y
        )
            res |= (1 << 3);

        if (
            lRect.pos.y + lRect.siz.y == rRect.pos.y && 
            lRect.pos.x < rRect.pos.x + rRect.siz.x &&
            lRect.pos.x + lRect.pos.x > rRect.pos.x
        )
            res |= (1 << 2);

        if (
            lRect.pos.y == rRect.pos.y + rRect.siz.y && 
            lRect.pos.x < rRect.pos.x + rRect.siz.x &&
            lRect.pos.x + lRect.pos.x > rRect.pos.x
        )
            res |= (1 << 4);

        return res;
    }
#pragma endregion
}