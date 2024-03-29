#ifndef _MIA_OBJECT_HPP
#define _MIA_OBJECT_HPP

#include "entity.hpp"

namespace mia
{
    class Object : public Entity
    {
    public:
        Object(); //TODO constructor
        ~Object();

    private:
        mia::string _name;
        bool active;
        uint32_t tag;
        Object *parent;
        int scene;

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
        
    };
}

#endif