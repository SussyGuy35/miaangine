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
            if (tilemap->HasTile(i, j)) _staticRectList.push_back(tilemap->GetRect(i, j));
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
                double tHit = 1;
                v2f point = v2f::zero(), normal = v2f::zero();
                if (BodycastRect(body, targetRect, body->velocity() * elapsedTime, tHit, point, normal)) 
                {
                    body->velocity() += v2f(
                        normal.x * std::abs(body->velocity().x) * (1 - tHit + CONTACT_OFFSET),
                        normal.y * std::abs(body->velocity().y) * (1 - tHit + CONTACT_OFFSET)
                    );
                }
            }

            ApplyBodyDynamic(body, elapsedTime);
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

    bool Physics::RaycastRect(const v2f &origin, const v2f &velocity, const rect &target, double &tHit, v2f &point, v2f &normal)
    {
        tHit = std::numeric_limits<double>::infinity();
        normal = v2f::zero();
        point = v2f::zero();

        v2f tnear = v2f(
            (target.pos.x - origin.x) / velocity.x,
            (target.pos.y - origin.y) / velocity.y
        );
        v2f tfar = v2f(
            (target.pos.x + target.siz.x - origin.x) / velocity.x,
            (target.pos.y + target.siz.y - origin.y) / velocity.y
        );

        if (tnear.x > tfar.x) std::swap<float>(tnear.x, tfar.x);
        if (tnear.y > tfar.y) std::swap<float>(tnear.y, tfar.y);

        if (tnear.x > tfar.y || tnear.y > tfar.x) return false;

        tHit = std::max(tnear.x, tnear.y);
		double hitFar = std::min(tfar.x, tfar.y);

		if (hitFar < 0) return false;

        point = origin + tHit * velocity;

        if (tnear.x > tnear.y)
            if (velocity.x < 0)
                normal = v2f::right();
            else
                normal = v2f::left();
        else if (tnear.x < tnear.y)
            if (velocity.y < 0)
                normal = v2f::up();
            else
                normal = v2f::down();

        return true;
    }

    bool Physics::BodycastRect(Body *body, const rect &targetRect, const v2f &step, double &tHit, v2f &point, v2f &normal)
    {
        tHit = std::numeric_limits<double>::infinity();
        normal = v2f::zero();
        point = v2f::zero();

        rect bodyRect = body->GetRect();

        if (body->velocity().x == 0 && body->velocity().y == 0) return false;

        rect expandTargetRect;
        expandTargetRect.pos = targetRect.pos - bodyRect.siz / 2;
        expandTargetRect.siz = targetRect.siz + bodyRect.siz;

        if (RaycastRect(bodyRect.pos + bodyRect.siz / 2, step, expandTargetRect, tHit, point, normal));
        {
            return (0 <= tHit && tHit <= 1.0);
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