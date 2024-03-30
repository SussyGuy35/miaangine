#ifndef _MIA_OBJECT_HPP
#define _MIA_OBJECT_HPP

#include "entity.hpp"

namespace mia
{
    class Component;

    class Object : public Entity
    {
    public:
    #pragma region Contructor Destructor
        Object(mia::string name = "unnamed");
        ~Object();
    #pragma endregion

    protected:
    #pragma region Attribute
        mia::string _name;
        bool _active;
        uint32_t _tag;
        Object *_parent;
        int _scene;
    #pragma endregion

    public:
    #pragma region Get-method
        mia::string name() const;
        bool isActive() const;
        uint32_t getTag() const;
        const Object* parent() const;
        int getScene() const;
    #pragma endregion

    #pragma region Set-method
        mia::string& name();
        Object* parent();
    #pragma endregion

    #pragma region Public method
        bool SetActive(bool newState);
        bool IsContainTag(int tag);
        uint32_t AddTag(int tag);
        uint32_t RemoveTag(int tag);
    #pragma endregion

    #pragma region Inherited method
        const char* ToStr() const override;
    #pragma endregion
    };
}

#endif