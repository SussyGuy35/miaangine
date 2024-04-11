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

        for (Body *body : _bodiesList)
        {
            if (body->getType() == _BODY_STATIC) continue;
            ApplyBodyDynamic(body, elapsedTime);
        }

        for (Body *body : _bodiesList)
        {
            if (body->getType() == _BODY_STATIC) continue;

            rect checkRect = body->GetRect();
            int resolveCount = 0;
            for (Body *other : _bodiesList) // FIXME
            {
                if (body == other) continue;
                if (checkRect.overlap(other->GetRect()) && resolveCount < MAX_COLLISION_RESOLUTION_SEARCH)
                {
                    ResolveBodyCollision(body, other);
                    resolveCount++;
                }
            }
        }
    }
#pragma endregion

#pragma region Private method
    void Physics::ApplyForceToBody(Body* body)
    {
        body->velocity() += body->force() / body->mass();
        body->force() = v2f::zero();
    }
    
    void Physics::ApplyBodyDynamic(Body *body, double elapsedTime)
    {
        for (Body *body : _bodiesList)
        {
            if (body->getType() == _BODY_STATIC) continue;

            body->master().position() += body->velocity() * elapsedTime;
        }
    }

    void Physics::ResolveBodyCollision(Body *body, Body *other)
    {
        rect bodyRect = body->GetRect();
        rect otherRect = other->GetRect();

        if (other->getType() == _BODY_STATIC)
        {
            if (body->velocity().x == 0 && body->velocity().y == 0)
            {
                //TODO
                return;
            } 

            float dx, dy;
            if (body->velocity().x > 0) dx = (bodyRect.pos.x + bodyRect.siz.x) - otherRect.pos.x;
            else                        dx = bodyRect.pos.x - (otherRect.pos.x + otherRect.siz.x);
            if (body->velocity().y > 0) dy = (bodyRect.pos.y + bodyRect.siz.y) - otherRect.pos.y;
            else                        dy = bodyRect.pos.y - (otherRect.pos.y + otherRect.siz.y);

            double tx = (body->velocity().x != 0 ? dx / body->velocity().x : std::numeric_limits<double>::infinity());
            double ty = (body->velocity().y != 0 ? dy / body->velocity().y : std::numeric_limits<double>::infinity());

            if (ty <= tx) 
            {
                body->master().position().y -= body->velocity().y * ty;
                body->velocity().y = 0;
            }
            else 
            {
                body->master().position().x -= body->velocity().x * tx;
                body->velocity().x = 0;
            }
        }
        else
        {
            
        }
    }
#pragma endregion
}