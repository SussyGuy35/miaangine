#include "object.hpp"

#include "transform.hpp"
#include "component.hpp"

namespace mia
{
#pragma region Contructor Destructor
    Object::Object(const char *name, v2f position, float scale):
        _name(name),
        _active(true),
        _scene(-1),
        _transform(new Transform(position, scale, nullptr, this))
    {}
    Object::Object(const char *name, float x, float y, float scale):
        _name(name),
        _active(true),
        _scene(-1),
        _transform(new Transform(v2f(x, y), scale, nullptr, this))
    {}
    Object::Object(const char *name, Transform* parent, v2f position, float scale):
        _name(name),
        _active(true),
        _scene(-1),
        _transform(new Transform(position, scale, parent, this))
    {}
    Object::Object(const char *name, Transform* parent, float x, float y, float scale):
        _name(name),
        _active(true),
        _scene(-1),
        _transform(new Transform(v2f(x, y), scale, parent, this))
    {}

    Object::~Object()
    {
        delete _transform;
    }
#pragma endregion

#pragma region GetSet-method
    string Object::name() const 
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
        return *_transform;
    }
    
    string& Object::name()
    {
        return _name;
    }
    bool Object::SetActive(bool newState)
    {
        _active = newState;
    }
    Transform& Object::transform() 
    {
        return *_transform;
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
        newComponent->SetMaster(_transform); //FIXME
        newComponent->Init();
    }
#pragma endregion

#pragma region Inherited method
    int Object::getID() const 
    {
        return _ENTITY_OBJECT;
    }
    const char* Object::ToStr() const
    {
        return string("Object");
    }
#pragma endregion
}