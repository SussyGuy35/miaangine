#include "world-object.hpp"

#include "graphic/portrait.hpp"
#include "physic/body.hpp"

#include "core/engine.hpp"

namespace mia
{
    WorldObject::WorldObject(Vector2 position):
        position(position),
        _portrait(nullptr),
        _body(nullptr)
    {}
    WorldObject::WorldObject(float x, float y):
        position(Vector2(x, y)),
        _portrait(nullptr),
        _body(nullptr)
    {}

    WorldObject::~WorldObject()
    {
        delete(_portrait);
        delete(_body);
    }

    Portrait *WorldObject::portrait()
    {
        if (_portrait == nullptr) 
        {
            SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_INFO, "WorldObject > Portrait: Null reference"); //FIXME
            return nullptr;
        }

        return _portrait;
    }

    Body *WorldObject::body()
    {
        if (_portrait == nullptr) 
        {
            SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_INFO, "WorldObject > Body: Null reference"); //FIXME
            return nullptr;
        }

        return _body;
    }

    void WorldObject::AttachPortrait(Portrait *portrait)
    {
        if (_portrait != nullptr) delete(_portrait);

        _portrait = portrait;
        _portrait->master = this;
    }

    void WorldObject::AttachBody(Body *body)
    {
        if (_body != nullptr) delete(_body);

        _body = body;
        _body->master = this;
    }

    void WorldObject::MakePortrait(Vector2 size, Vector2 offset)
    {
        if (_portrait != nullptr) delete(_portrait);

        _portrait = new Portrait(size, offset);
        _portrait->master = this;
    }
    void WorldObject::MakePortrait(float sx, float sy, float ox, float oy)
    {
        if (_portrait != nullptr) delete(_portrait);
        _portrait = new Portrait(sx, sy, ox, oy);
        _portrait->master = this;
    }

    void WorldObject::MakeBody(Vector2 size, Vector2 offset)
    {
        if (_body != nullptr) delete(_body);

        _body = new Body(size, offset);
        _body->master = this;
        physicWorld->AddBody(_body);
    }
    void WorldObject::MakeBody(float sx, float sy, float ox, float oy)
    {
        if (_body != nullptr) delete(_body);

        _body = new Body(sx, sy, ox, oy);
        _body->master = this;
        physicWorld->AddBody(_body);
    }

    void WorldObject::Log()
    {
        SDL_Log(":: %f : %llu ::\n"
                "WorldObject > Position(%.2f, %.2f)\n<>",
                Time::time, Time::stepCount,
                position.x, position.y);
    }
}