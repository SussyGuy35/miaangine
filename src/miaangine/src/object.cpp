#include "object.hpp"

#include "component.hpp"

namespace mia
{
#pragma region Contructor Destructor
    Object::Object(const char *name, Transform *transform):
        Entity(_ENTITY_OBJECT),
        _name(name),
        _active(true),
        _scene(-1), //TODO scene
        _transform(transform)
    {}

    Object::~Object()
    {}
#pragma endregion

#pragma region GetSet-method
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
    const Transform* Object::transform() const
    {
        return _transform;
    }
    
    mia::string& Object::name()
    {
        return _name;
    }
    bool Object::SetActive(bool newState)
    {
        _active = newState;
    }
    Transform* Object::transform() 
    {
        return _transform;
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
    void Object::AddComponent(Component *newComponent)
    {
        _components.push_back(newComponent);
        newComponent->Init();
        newComponent->SetMaster(_transform);
    }
#pragma endregion

#pragma region Inherited method
    const char* Object::ToStr() const
    {
        return mia::string("Object");
    }
#pragma endregion
}