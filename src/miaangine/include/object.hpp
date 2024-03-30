#ifndef _MIA_OBJECT_HPP
#define _MIA_OBJECT_HPP

#include "entity.hpp"

namespace mia
{
    class Component;

    class Object : public Entity
    {
    public:
        Object(const char *name = "unnamed");
        virtual ~Object();

    protected:
        mia::string _name;
        bool _active;
        uint32_t _tag;
        int _scene;

    public:
        mia::string name() const;
        bool isActive() const;
        uint32_t getTag() const;
        int getScene() const;

        mia::string& name();
        bool SetActive(bool newState);
        bool IsContainTag(int tag);
        uint32_t AddTag(int tag);
        uint32_t RemoveTag(int tag);

    public:
        const char* ToStr() const override;
    };
}

#endif