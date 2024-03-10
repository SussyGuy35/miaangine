#include "world-object.hpp"

#include "graphic/portrait.hpp"
#include "physics/body.hpp"

#include "core/engine.hpp"

namespace mia
{
    WorldObject::WorldObject(const char* name, Vector2 position):
        GameObject(name),
        position(position)
    {}
    WorldObject::WorldObject(const char* name, float x, float y):
        GameObject(name),
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
        portrait->ShiftMaster(this);
        _portraits.push_back(portrait);
    }

    void WorldObject::AttachBody(Body *body)
    {
        body->ShiftMaster(this);
        _bodies.push_back(body);
    }

    void WorldObject::MakePortrait(Vector2 size, Vector2 offset)
    {
        Portrait *portrait = new Portrait(size, offset);

        portrait->ShiftMaster(this);
        _portraits.push_back(portrait);
    }
    void WorldObject::MakePortrait(float sx, float sy, float ox, float oy)
    {
        Portrait *portrait = new Portrait(sx, sy, ox, oy);

        portrait->ShiftMaster(this);
        _portraits.push_back(portrait);
    }

    void WorldObject::MakeBody(Vector2 size, Vector2 offset)
    {
        Body *body = new Body(size, offset);

        body->ShiftMaster(this);
        _bodies.push_back(body);
    }
    void WorldObject::MakeBody(float sx, float sy, float ox, float oy)
    {
        Body *body = new Body(sx, sy, ox, oy);

        body->ShiftMaster(this);
        _bodies.push_back(body);
    }
}