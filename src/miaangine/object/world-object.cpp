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
        delete(portrait);
        delete(body);
    }

    void WorldObject::AttachPortrait(Portrait *portrait)
    {
        this->portrait = portrait;
        this->portrait->master = this;
    }

    void WorldObject::AttachBody(Body *body)
    {
        this->body = body;
        this->body->master = this;
    }

    void WorldObject::MakePortrait(Vector2 size, Vector2 offset)
    {
        portrait = new Portrait(size, offset);
        portrait->master = this;
    }
    void WorldObject::MakePortrait(float sx, float sy, float ox, float oy)
    {
        portrait = new Portrait(sx, sy, ox, oy);
        portrait->master = this;
    }

    void WorldObject::MakeBody(Vector2 size, Vector2 offset)
    {
        body = new Body(size, offset);
        body->master = this;
        physicWorld->AddBody(body);
    }
    void WorldObject::MakeBody(float sx, float sy, float ox, float oy)
    {
        body = new Body(sx, sy, ox, oy);
        body->master = this;
        physicWorld->AddBody(body);
    }

    void WorldObject::Log()
    {
        SDL_Log(":: %f : %llu ::\n"
                "WorldObject > Position(%.2f, %.2f)\n<>",
                Time::time, Time::stepCount,
                position.x, position.y);
    }
}