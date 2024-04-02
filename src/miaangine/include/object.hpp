#ifndef _MIA_OBJECT_HPP
#define _MIA_OBJECT_HPP

#include "common.hpp"

#include "entity.hpp"

namespace mia
{
    class Component;
    class Transform;

    class Object : public Entity
    {
    public:
        Object(const char *name = "Untitled", mia::v2f position = mia::v2f::zero(), float scale = 1);
        Object(const char *name, float x, float y, float scale = 1);
        Object(const char *name, Object* parent, mia::v2f position = mia::v2f::zero(), float scale = 1);
        Object(const char *name, Object* parent, float x, float y, float scale = 1);
        virtual ~Object();

    protected:
        mia::string _name;
        bool _active;
        uint32_t _tag;
        int _scene;
        Transform _transform;
        std::vector<Component*> _components;
        Object *_parent;

    public:
        mia::string name() const;
        bool isActive() const;
        uint32_t getTag() const;
        int getScene() const;
        const Transform& transform() const;
        const Object* parent() const;

        mia::string& name();
        bool SetActive(bool newState);
        Transform& transform();
        Object* parent();
        
        bool IsContainTag(int tag);
        uint32_t AddTag(int tag);
        uint32_t RemoveTag(int tag);
        void AddComponent(Component *newComponent);

    public:
        int getID() const override;
        const char* ToStr() const override;
    };
}

#endif