#include "object.hpp"

namespace mia
{
#pragma region Contructor Destructor
    Object::Object(const char *name):
        Entity(ENTITY_OBJECT),
        _name(name),
        _active(true),
        _scene(-1) //TODO scene
    {}

    Object::~Object()
    {}
#pragma endregion

#pragma region Get-method
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
    int Object::getScene() const
    {
        return _scene;
    }
#pragma endregion

#pragma region Set-method
    mia::string& Object::name()
    {
        return _name;
    }
#pragma endregion

#pragma region Public method
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
#pragma endregion

#pragma region Inherited method
    const char* Object::ToStr() const
    {
        return mia::string("Object");
    }
#pragma endregion
}