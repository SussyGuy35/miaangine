#ifndef _MIA_OBJECT_HPP
#define _MIA_OBJECT_HPP

#include "entity.hpp"

namespace mia
{
    class Object : public Entity
    {
    public:
        Object(mia::string name = "unnamed");
        ~Object();

    private:
        mia::string _name;
        bool _active;
        uint32_t _tag;
        Object *_parent;
        int _scene;

    public:
        mia::string name() const;
        bool isActive() const;
        uint32_t getTag() const;
        const Object* parent() const;
        int getScene() const;

        mia::string& name();
        Object* parent();

        bool SetActive(bool newState);
        bool IsContainTag(int tag);
        uint32_t AddTag(int tag);
        uint32_t RemoveTag(int tag);
        
        mia::string ToStr() override;
    };
}

#endif