#include "physics.hpp"

#include "time.hpp"

#include "event-dispatcher.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Physics::Physics():
        _bodiesList(std::vector<Body*>()),
        _tilemapsList(std::vector<Tilemap*>()),
        _staticRectList(std::vector<rect>())
    {}

    Physics::~Physics()
    {}
#pragma endregion

#pragma region Public method
    void Physics::RegisterBody(Body *body)
    {
        _bodiesList.push_back(body);
        if (body->getType() == _BODY_STATIC) _staticRectList.push_back(body->GetRect());
    }
    void Physics::UnregisterBody(Body *body)
    {
        auto bodyIterator = std::find(_bodiesList.begin(), _bodiesList.end(), body);
        if (bodyIterator != _bodiesList.end())
        {
            _bodiesList.erase(bodyIterator);
        }

        // auto rectIterator = std::find(_staticRectList.begin(), _staticRectList.end(), body->GetRect());
        // if (rectIterator != _staticRectList.end())
        // {
        //     _staticRectList.erase(rectIterator);
        // }
    }

    void Physics::RegisterTilemap(Tilemap *tilemap)
    {
        _tilemapsList.push_back(tilemap);

        for (int i = 0; i < tilemap->width(); i++) for (int j = 0; j < tilemap->height(); j++)
            _staticRectList.push_back(tilemap->GetRect(i, j));
    }
    void Physics::UnregisterTilemap(Tilemap *tilemap)
    {
        auto tilemapIterator = std::find(_tilemapsList.begin(), _tilemapsList.end(), tilemap);
        if (tilemapIterator != _tilemapsList.end())
        {
            _tilemapsList.erase(tilemapIterator);
        }

        // for (int i = 0; i < tilemap->width(); i++) for (int j = 0; j < tilemap->height(); j++)
        // {
        //     auto rectIterator = std::find(_staticRectList.begin(), _staticRectList.end(), tilemap->GetRect(i, j));
        //     if (rectIterator != _staticRectList.end())
        //     {
        //         _staticRectList.erase(rectIterator);
        //     }
        // }
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

            for (const rect &targetRect : _staticRectList)
            {
                float timeHitScale = 1;
                v2f hit = v2f::zero(), normal = v2f::zero();
                if (BodycastRect(body, targetRect, body->velocity() * elapsedTime, timeHitScale, hit, normal)) 
                {
                    printf("%f %f x %f %f, %f : ", body->velocity().x, body->velocity().y, normal.x, normal.y, timeHitScale);

                    body->velocity() += v2f(normal.x * std::abs(body->velocity().x) * (1 - timeHitScale),
                                            normal.y * std::abs(body->velocity().y) * (1 - timeHitScale)
                                        );

                    printf("%f %f\n", body->velocity().x, body->velocity().y);
                }

                ApplyBodyDynamic(body, elapsedTime);
            }

        }

        EventDispatcher::Instance().Notify(_EVENT_AFTER_PHYSICS_CALCULATION);
    }

    bool Physics::Query(rect trect)
    {
        for (const rect &other : _staticRectList)
        {
            if (trect.overlap(other)) return true;
        }
        return false;
    }
    bool Physics::Query(float x, float y, float sx, float sy)
    {
        rect trect = { {x, y}, {sx, sy} };
        for (const rect &other : _staticRectList)
        {
            if (trect.overlap(other)) return true;
        }
        return false;
    }

    bool Physics::RaycastRect(const v2f &origin, const v2f &velocity, const rect &target, float &timeHit, v2f &hit, v2f &normal)
    {
        float txNear = (target.pos.x - origin.x) / velocity.x;
        float txFar  = (target.pos.x + target.siz.x - origin.x) / velocity.x;
        float tyNear = (target.pos.y - origin.y) / velocity.y;
        float tyFar  = (target.pos.y + target.siz.y - origin.y) / velocity.y;

        if (txNear > txFar) std::swap(txNear, txFar);
        if (tyNear > tyFar) std::swap(tyNear, tyFar);

        if (txNear > tyFar || tyNear > txFar) return false;

        float tHitNear = std::max(txNear, tyNear);
        float tHitFar = std::min(txFar, tyFar);

        if (tHitFar < 0) return false;

        timeHit = tHitNear;
        hit = origin + tHitNear * velocity;
        if (txNear > tyNear)
        {
            if (velocity.x < 0)
                normal = v2f::right();
            else 
                normal = v2f::left();
        }
        else if (txNear < tyNear)
        {
            if (velocity.y < 0)
                normal = v2f::up();
            else 
                normal = v2f::down();
        }

        return true;
    }

    bool Physics::BodycastRect(Body *body, const rect &targetRect, const v2f &step, float &timeHit, v2f &hit, v2f &normal)
    {
        rect bodyRect = body->GetRect();

        if (body->velocity().x == 0 && body->velocity().y == 0) return false;

        rect expandTargetRect;
        expandTargetRect.pos = targetRect.pos - bodyRect.siz / 2;
        expandTargetRect.siz = targetRect.siz + bodyRect.siz;

        if (RaycastRect(bodyRect.pos + bodyRect.siz / 2, step, expandTargetRect, timeHit, hit, normal));
        {
            if (0 <= timeHit && timeHit <= 1.0) return true;
        }

        return false;
    }
#pragma endregion

#pragma region Private method
    void Physics::ApplyForceToBody(Body* body)
    {
        body->velocity() += body->force() * Time::Instance().deltaTime() / body->mass();
        body->force() = v2f::zero();
    }
    
    void Physics::ApplyBodyDynamic(Body *body, double elapsedTime)
    {
        if (body->getType() == _BODY_STATIC) return;

        body->master().position() += body->velocity() * elapsedTime;
    }
#pragma endregion
}