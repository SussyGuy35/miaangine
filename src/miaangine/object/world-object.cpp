#include "world-object.hpp"

#include "core/engine-components.hpp"

#include "graphic/portrait.hpp"
#include "physics/body.hpp"

namespace mia
{
    WorldObject::WorldObject(const char* name, vector2 position):
        GameObject(name),
        _position(position),
        _body(nullptr)
    {}
    WorldObject::WorldObject(const char* name, float x, float y):
        GameObject(name),
        _position(vector2(x, y)),
        _body(nullptr)
    {}

    WorldObject::~WorldObject()
    {
        delete(_body);

        for (auto& portrait : _portraits) delete(portrait);
        _portraits.clear();
    }

    vector2& WorldObject::position()
    {
        return _position;
    }
    Portrait& WorldObject::portrait(int index)
    {
        if (_portraits.empty() || index >= _portraits.size()) 
        {
            mia::DebugManager::Instance().Warning("[WorldObject(%s)] Warning: [Portrait(%d)] Null reference; Created new [Portrait(%d)]", name.str(), index, index);
            return MakePortrait();
        }

        return *_portraits[index];
    }
    Body& WorldObject::body()
    {
        if (_body == nullptr) 
        {
            mia::DebugManager::Instance().Warning("[WorldObject(%s)] Warning: [Body] Null reference; Created new [Body]", name.str());
            return MakeBody();
        }

        return *_body;
    }

    const vector2& WorldObject::position() const
    {
        return _position;
    }
    const Portrait& WorldObject::portrait(int index) const
    {
        if (_portraits.empty() || index >= _portraits.size()) 
        {
            mia::DebugManager::Instance().Warning("[WorldObject(%s)] Warning: [Portrait(%d)] Null reference; Return Null", name.str(), index, index);
        }

        return *_portraits[index];
    }
    const Body& WorldObject::body() const
    {
        if (_body == nullptr) 
        {
            mia::DebugManager::Instance().Warning("[WorldObject(%s)] Warning: [Body] Null reference; Return Null", name.str());
        }

        return *_body;
    }

    Portrait& WorldObject::AttachPortrait(Portrait *portrait)
    {
        portrait->ShiftMaster(this);
        _portraits.push_back(portrait);

        return *portrait;
    }

    Body& WorldObject::AttachBody(Body *body)
    {
        body->ShiftMaster(this);
        delete(_body);
        _body = body;

        return *body;
    }

    Portrait& WorldObject::MakePortrait(const char* dir, vector2 scale, vector2 offset)
    {
        Portrait *portrait = new Portrait(dir, scale, offset);

        portrait->ShiftMaster(this);
        _portraits.push_back(portrait);

        return *portrait;
    }
    Portrait& WorldObject::MakePortrait(const char* dir, float sx, float sy, float ox, float oy)
    {
        Portrait *portrait = new Portrait(dir, sx, sy, ox, oy);

        portrait->ShiftMaster(this);
        _portraits.push_back(portrait);

        return *portrait;
    }
    Portrait& WorldObject::MakePortrait(vector2 scale, vector2 offset)
    {
        Portrait *portrait = new Portrait(scale, offset);

        portrait->ShiftMaster(this);
        _portraits.push_back(portrait);

        return *portrait;
    }
    Portrait& WorldObject::MakePortrait(float sx, float sy, float ox, float oy)
    {
        Portrait *portrait = new Portrait(sx, sy, ox, oy);

        portrait->ShiftMaster(this);
        _portraits.push_back(portrait);

        return *portrait;
    }

    Body& WorldObject::MakeBody(float mass, vector2 initForce)
    {
        if (_body != nullptr)
        {
            mia::DebugManager::Instance().Warning("[WorldObject(%s)] Warning: [Body] Already existed. ", name.str());
            return *_body;
        }

        _body = new Body(mass, initForce);
        _body->ShiftMaster(this);

        return *_body;
    }
}