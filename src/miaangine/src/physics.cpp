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
            ApplyForceToBody(body);

            if (body->getType() == _BODY_STATIC) StaticBodyHandle(body, elapsedTime);
            if (body->getType() == _BODY_DYNAMIC) DynamicBodyHandle(body, elapsedTime);
            if (body->getType() == _BODY_TRIGGER) TriggerBodyHandle(body, elapsedTime);
        }
    }
#pragma endregion

#pragma region Private method
    void Physics::ApplyForceToBody(Body *body)
    {
        body->velocity() += body->force() / body->mass();
        body->force() = v2f::zero();
    }

    void Physics::StaticBodyHandle(Body *body, double elapsedTime)
    {
        body->master().position() += body->velocity() * elapsedTime;
    }
    void Physics::DynamicBodyHandle(Body *body, double elapsedTime)
    {
        int touchedFaces = 0;
        for (int i = 0; i < MAX_COLLISION_RESOLUTION; i++)
        {
            double updateTime = elapsedTime;

            for (Body* other : _bodiesList)
            {
                if (body == other || body->getType() == _BODY_TRIGGER) continue;

                updateTime = QueryCollisionTimeResolution(body, other, updateTime);
                touchedFaces |= QueryCollisionTouchResolution(body, other);
            }
            
            if ( ((touchedFaces >> 1) & 1) || ((touchedFaces >> 3) & 1) ) body->velocity().x = 0;
            if ( ((touchedFaces >> 2) & 1) || ((touchedFaces >> 4) & 1) ) body->velocity().y = 0;

            body->master().position() += body->velocity() * updateTime;

            elapsedTime -= updateTime;
            if (elapsedTime <= 0) break;
        }
    }
    void Physics::TriggerBodyHandle(Body *body, double elapsedTime)
    {
        // TODO
        body->master().position() += body->velocity() * elapsedTime;
    }

    double Physics::QueryCollisionTimeResolution(Body *body, Body *other, double maxResTime)
    {
        rect thisRect = body->GetRect();
        rect otherRect = other->GetRect();

        if (body->velocity().x == 0 && body->velocity().y == 0) 
        {
            return maxResTime;
        }
        else if (body->velocity().x == 0)
        {
            if (
                thisRect.pos.x + thisRect.siz.x <= otherRect.pos.x ||
                thisRect.pos.x                  >= otherRect.pos.x + otherRect.siz.x
            )
                return maxResTime;

            float dyEnter, tyEnter;

            if (body->velocity().y > 0)
                dyEnter =  otherRect.pos.y                    - (thisRect.pos.y + thisRect.siz.y);
            else 
                dyEnter = (otherRect.pos.y + otherRect.siz.y) -  thisRect.pos.y;

            tyEnter = dyEnter / body->velocity().y;

            if (tyEnter < 0 || tyEnter > maxResTime) return maxResTime;
            return tyEnter;
        }
        else if (body->velocity().y == 0)
        {
            if (
                thisRect.pos.y + thisRect.siz.y <= otherRect.pos.y ||
                thisRect.pos.y                  >= otherRect.pos.y + otherRect.siz.y
            )
                return maxResTime;

            float dxEnter, txEnter;
            if (body->velocity().x > 0)
                dxEnter =  otherRect.pos.x                    - (thisRect.pos.x + thisRect.siz.x);
            else 
                dxEnter = (otherRect.pos.x + otherRect.siz.x) -  thisRect.pos.x;

            txEnter = dxEnter / body->velocity().x;

            if (txEnter < 0 || txEnter > maxResTime) return maxResTime;
            return txEnter;
        }
        else 
        {
            float dxEnter, dxExit;
            float dyEnter, dyExit;

            if (body->velocity().x > 0)
            {
                dxEnter =  otherRect.pos.x                    - (thisRect.pos.x + thisRect.siz.x);
                dxExit  = (otherRect.pos.x + otherRect.siz.x) -  thisRect.pos.x;
            }
            else 
            {
                dxEnter = (otherRect.pos.x + otherRect.siz.x) -  thisRect.pos.x;
                dxExit  =  otherRect.pos.x                    - (thisRect.pos.x + thisRect.siz.x);
            }

            if (body->velocity().y > 0)
            {
                dyEnter =  otherRect.pos.y                    - (thisRect.pos.y + thisRect.siz.y);
                dyExit  = (otherRect.pos.y + otherRect.siz.y) -  thisRect.pos.y;
            }
            else 
            {
                dyEnter = (otherRect.pos.y + otherRect.siz.y) -  thisRect.pos.y;
                dyExit  =  otherRect.pos.y                    - (thisRect.pos.y + thisRect.siz.y);
            }

            float txEnter = dxEnter / body->velocity().x;
            float tyEnter = dyEnter / body->velocity().y;
            float txExit  = dxExit  / body->velocity().x;
            float tyExit  = dyExit  / body->velocity().y;

            float enterTime = std::max(txEnter, tyEnter);
            float exitTime  = std::min(txExit , tyExit );
            if (enterTime >= exitTime || enterTime < 0 || enterTime > maxResTime) return maxResTime;
            return enterTime;
        }
    }
    int Physics::QueryCollisionTouchResolution(Body *body, Body *other)
    {
        rect thisRect = body->GetRect();
        rect otherRect = other->GetRect();

        int res = 0;
        
        if (
            body->velocity().x > 0 &&
            thisRect.pos.x + thisRect.siz.x == otherRect.pos.x && 
            thisRect.pos.y < otherRect.pos.y + otherRect.siz.y &&
            thisRect.pos.y + thisRect.pos.y > otherRect.pos.y
        )
            res |= (1 << 1);
        
        if (
            body->velocity().x < 0 &&
            thisRect.pos.x == otherRect.pos.x + otherRect.siz.x && 
            thisRect.pos.y < otherRect.pos.y + otherRect.siz.y &&
            thisRect.pos.y + thisRect.pos.y > otherRect.pos.y
        )
            res |= (1 << 3);

        if (
            body->velocity().y > 0 &&
            thisRect.pos.y + thisRect.siz.y == otherRect.pos.y && 
            thisRect.pos.x < otherRect.pos.x + otherRect.siz.x &&
            thisRect.pos.x + thisRect.pos.x > otherRect.pos.x
        )
            res |= (1 << 2);

        if (
            body->velocity().y < 0 &&
            thisRect.pos.y == otherRect.pos.y + otherRect.siz.y && 
            thisRect.pos.x < otherRect.pos.x + otherRect.siz.x &&
            thisRect.pos.x + thisRect.pos.x > otherRect.pos.x
        )
            res |= (1 << 4);

        return res;
    }
#pragma endregion
}