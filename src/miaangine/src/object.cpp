#include "object.hpp"

namespace mia
{
    Object::Object(mia::string name):
        Entity(ENTITY_OBJECT),
        _name(name),
        _active(true),
        _parent(nullptr),
        _scene(-1) //TODO
    {}

    Object::~Object()
    {}

    mia::string Object::name() const 
    {
        return _name;
    }
    bool Object::isActive() const
    {
        return _active;
    }
    uint32_t Object::getTag() const
    {
        return _tag;
    }
    const Object* Object::parent() const
    {
        // TODO add warn null
        return _parent;
    }
    int Object::getScene() const
    {
        return _scene;
    }

    mia::string& Object::name()
    {
        return _name;
    }
    Object* Object::parent()
    {
        // TODO add warn null
        return _parent;
    }

    bool Object::SetActive(bool newState)
    {
        _active = newState;
    }
    bool Object::IsContainTag(int tag)
    {
        // TODO Add safety check
        return ((_tag >> tag) & 1);
    }
    uint32_t Object::AddTag(int tag)
    {
        _tag |= (1 << tag);
    }
    uint32_t Object::RemoveTag(int tag)
    {
        _tag &= ~(1 << tag);
    }

    mia::string Object::ToStr() 
    {
        return mia::string("Object");
    }
}