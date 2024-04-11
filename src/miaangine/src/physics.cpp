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
        for (Body *body : _bodiesList)
        {
            ApplyForceToBody(body);

            // TouchedBodyHandle(body);
            if (body->getType() == _BODY_STATIC) StaticBodyHandle(body, elapsedTime);
            if (body->getType() == _BODY_DYNAMIC) DynamicBodyHandle(body, elapsedTime);
            if (body->getType() == _BODY_TRIGGER) TriggerBodyHandle(body, elapsedTime);
            // TouchedBodyHandle(body);
        }
    }
#pragma endregion

#pragma region Private method
    void Physics::ApplyForceToBody(Body *body)
    {
        body->velocity() += body->force() / body->mass();
        body->force() = v2f::zero();
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
    void Physics::StaticBodyHandle(Body *body, double elapsedTime)
    {
        body->master().position() += body->velocity() * elapsedTime;
    }
    void Physics::DynamicBodyHandle(Body *body, double elapsedTime)
    {
        rect bodyRect = body->GetRect();
        rect consideredRect;
        consideredRect.pos.x = std::min(bodyRect.pos.x, bodyRect.pos.x + body->velocity().x * float(elapsedTime));
        consideredRect.pos.y = std::min(bodyRect.pos.y, bodyRect.pos.y + body->velocity().y * float(elapsedTime));
        consideredRect.siz.x = bodyRect.siz.x + std::abs(body->velocity().x * float(elapsedTime));
        consideredRect.siz.y = bodyRect.siz.y + std::abs(body->velocity().y * float(elapsedTime));

        Renderer::Instance().DrawRect({ {consideredRect.pos.x, consideredRect.pos.y + 2}, consideredRect.siz });

        double updateTime = elapsedTime;
        for (Body *other : _bodiesList) // TODO 
        {
            if (body == other) continue;
            if (!consideredRect.overlap(other->GetRect())) continue;

            v2f deltaVelocity = body->velocity() - other->velocity();

            double collideTime = GetTimeToCollide(body->GetRect(), other->GetRect(), deltaVelocity);
            updateTime = std::min(updateTime, collideTime);
        // printf("%s : %s > %f\n", body->master().name().str(), other->master().name().str(), collideTime);
        }

        // printf(" > %s : %f %f\n", body->master().name().str(), body->velocity().x * updateTime, body->velocity().y * updateTime);
        body->master().position() += body->velocity() * updateTime;
    }
    void Physics::TriggerBodyHandle(Body *body, double elapsedTime)
    {
        // TODO
        body->master().position() += body->velocity() * elapsedTime;
    }

    double Physics::GetTimeToCollide(const rect& lRect, const rect& rRect, const v2f& deltaVelocity)
    {
        float lxNear, rxNear, lxFar, rxFar;
        float lyNear, ryNear, lyFar, ryFar;

        if (deltaVelocity.x > 0) 
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

        if (deltaVelocity.y > 0) 
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
        
        if (deltaVelocity.x == 0)
        {
            txEnter = std::numeric_limits<double>::infinity();
            if (lRect.pos.x < rRect.pos.x + rRect.siz.x && lRect.pos.x + lRect.siz.x > rRect.pos.x) txEnter = -std::numeric_limits<double>::infinity();
            txExit  = std::numeric_limits<double>::infinity();
        }
        else
        {
            txEnter = dxEnter / deltaVelocity.x;
            txExit  = dxExit  / deltaVelocity.x;
        }

        if (deltaVelocity.y == 0)
        {
            tyEnter = std::numeric_limits<double>::infinity();
            if (lRect.pos.y < rRect.pos.y + rRect.siz.y && lRect.pos.y + lRect.siz.y > rRect.pos.y) tyEnter = -std::numeric_limits<double>::infinity();
            tyExit  = std::numeric_limits<double>::infinity();
        }
        else
        {
            tyEnter = dyEnter / deltaVelocity.y;
            tyExit  = dyExit  / deltaVelocity.y;
        }

        double enterTime = std::max(txEnter, tyEnter);
        double exitTime  = std::min(txExit , tyExit );

        if (enterTime >= exitTime || enterTime < 0) return std::numeric_limits<double>::infinity();
        return enterTime;
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