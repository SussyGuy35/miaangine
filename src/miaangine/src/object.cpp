#include "object.hpp"

#include "portrait.hpp"
#include "body.hpp"

namespace mia
{
#pragma region Contructor Destructor
    Object::Object(const char *name, v2f position):
        _name(name),
        _tag(0),
        _position(position),
        _portrait(nullptr),
        _body(nullptr)
    {}
    Object::Object(const char *name, float x, float y):
        _name(name),
        _tag(0),
        _position(v2f(x, y)),
        _portrait(nullptr),
        _body(nullptr)
    {}
    Object::Object(float x, float y):
        _name("Untitled"),
        _tag(0),
        _position(v2f(x, y)),
        _portrait(nullptr),
        _body(nullptr)
    {}

    Object::~Object()
    {
        // TODO Add destroy method

        delete _portrait;
        delete _body;
    }
#pragma endregion

#pragma region GetSet-method
    string Object::name() const
    {
        return _name;
    }
    uint32_t Object::getTag() const
    {
        return _tag;
    }
    const v2f& Object::position() const
    {
        return _position;
    }
    const Portrait& Object::portrait() const
    {
        if (!_portrait) 
        {
            // FIXME
        }

        return *_portrait;
    }
    const Body& Object::body() const
    {
        if (!_body) 
        {
            // FIXME
        }

        return *_body;
    }

    string& Object::name()
    {
        return _name;
    }
    v2f& Object::position()
    {
        return _position;
    }
    Portrait& Object::portrait()
    {
        if (!_portrait) 
        {
            // FIXME
        }

        return *_portrait;
    }
    Body& Object::body()
    {
        if (!_body) 
        {
            // FIXME
        }

        return *_body;
    }
#pragma endregion

#pragma region Public method
    bool Object::IsContainTag(int tag)
    {
        // TODO safety
        return ((_tag >> tag) & 1);
    }
    uint32_t Object::AddTag(int tag)
    {
        // TODO safety
        _tag |= (1 << tag);
    }
    uint32_t Object::RemoveTag(int tag)
    {
        // TODO safety
        _tag &= ~(1 << tag);
    }
#pragma endregion

#pragma region Inherited method
    int Object::getID() const 
    {
        return _ENTITY_OBJECT;
    }
    const char* Object::ToStr() const
    {
        return "Object";
    }
#pragma endregion
}