#include "world-object.hpp"

#include "graphic/portrait.hpp"
#include "physic/body.hpp"

#include "core/engine.hpp"

namespace mia
{
    WorldObject::WorldObject(Vector2 position):
        position(position)
    {}
    WorldObject::WorldObject(float x, float y):
        position(Vector2(x, y))
    {}

    WorldObject::~WorldObject()
    {
        for (auto& body : _bodies) delete(body);
        _bodies.clear();

        for (auto& portrait : _portraits) delete(portrait);
        _portraits.clear();
    }

    Portrait *WorldObject::portrait(int index)
    {
        if (_portraits.empty()) 
        {
            SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_INFO, "WorldObject > Portrait: Null reference"); //FIXME
            return nullptr;
        }

        return _portraits[index];
    }

    Body *WorldObject::body(int index)
    {
        if (_bodies.empty()) 
        {
            SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_INFO, "WorldObject > Body: Null reference"); //FIXME
            return nullptr;
        }

        return _bodies[index];
    }

    void WorldObject::AttachPortrait(Portrait *portrait)
    {
        _portraits.push_back(portrait);
        portrait->master = this;
        portrait->position = &position;
    }

    void WorldObject::AttachBody(Body *body)
    {
        _bodies.push_back(body);
        body->master = this;
        body->position = &position;
    }

    void WorldObject::MakePortrait(Vector2 size, Vector2 offset)
    {
        Portrait *portrait = new Portrait(size, offset);

        _portraits.push_back(portrait);
        portrait->master = this;
        portrait->position = &position;
    }
    void WorldObject::MakePortrait(float sx, float sy, float ox, float oy)
    {
        Portrait *portrait = new Portrait(sx, sy, ox, oy);

        _portraits.push_back(portrait);
        portrait->master = this;
        portrait->position = &position;
    }

    void WorldObject::MakeBody(Vector2 size, Vector2 offset)
    {
        Body *body = new Body(size, offset);

        _bodies.push_back(body);
        body->master = this;
        body->position = &position;
        physicWorld->AddBody(body);
    }
    void WorldObject::MakeBody(float sx, float sy, float ox, float oy)
    {
        Body *body = new Body(sx, sy, ox, oy);

        _bodies.push_back(body);
        body->master = this;
        body->position = &position;
        physicWorld->AddBody(body);
    }

    void WorldObject::Log() //TODO
    {
        SDL_Log("%.2f - %llu | "
                "WorldObject > Position(%.2f, %.2f); Portrait Count(%d); Body Count(%d)",
                Time::time, Time::stepCount,
                position.x, position.y, static_cast<int>(_portraits.size()), static_cast<int>(_bodies.size()));
    }
}