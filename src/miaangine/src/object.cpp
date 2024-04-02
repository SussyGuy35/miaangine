#include "object.hpp"

#include "transform.hpp"
#include "component.hpp"

namespace mia
{
#pragma region Contructor Destructor
    Object::Object(const char *name, mia::v2f position, float scale):
        _name(name),
        _active(true),
        _scene(-1),
        _transform(Transform(position, scale)),
        _parent(nullptr)
    {}
    Object::Object(const char *name, float x, float y, float scale):
        _name(name),
        _active(true),
        _scene(-1),
        _transform(Transform(v2f(x, y), scale)),
        _parent(nullptr)
    {}
    Object::Object(const char *name, Object* parent, mia::v2f position, float scale):
        _name(name),
        _active(true),
        _scene(-1),
        _transform(Transform(position, scale)),
        _parent(parent)
    {}
    Object::Object(const char *name, Object* parent, float x, float y, float scale):
        _name(name),
        _active(true),
        _scene(-1),
        _transform(Transform(v2f(x, y), scale)),
        _parent(nullptr)
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
    const Transform& Object::transform() const
    {
        return _transform;
    }
    const Object* Object::parent() const 
    {
        return _parent;
    }
    
    mia::string& Object::name()
    {
        return _name;
    }
    bool Object::SetActive(bool newState)
    {
        _active = newState;
    }
    Transform& Object::transform() 
    {
        return _transform;
    }
    Object* Object::parent()
    {
        return _parent;
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
        // newComponent->SetMaster(this); //FIXME
    }
#pragma endregion

#pragma region Inherited method
    int Object::getID() const 
    {
        return _ENTITY_OBJECT;
    }
    const char* Object::ToStr() const
    {
        return mia::string("Object");
    }
#pragma endregion
}