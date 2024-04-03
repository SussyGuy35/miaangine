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
        Object(const char *name = "Untitled", v2f position = v2f::zero(), v2f scale = v2f::one());
        Object(const char *name, float x, float y, float sx = 1, float sy = 1);
        Object(const char *name, Transform* parent, v2f position = v2f::zero(), v2f scale = v2f::one());
        Object(const char *name, Transform* parent, float x, float y, float sx = 1, float sy = 1);
        virtual ~Object();

    protected:
        string _name;
        bool _active;
        uint32_t _tag;
        int _scene;
        Transform *_transform;
        std::vector<Component*> _components;

    public:
        string name() const;
        bool isActive() const;
        uint32_t getTag() const;
        int getScene() const;
        const Transform& transform() const;

        string& name();
        bool SetActive(bool newState);
        Transform& transform();
        
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