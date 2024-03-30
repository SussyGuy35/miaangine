#ifndef _MIA_OBJECT_HPP
#define _MIA_OBJECT_HPP

#include "entity.hpp"

namespace mia
{
    class Component;

    class Object : public Entity
    {
    #pragma region Contructor Destructor
    protected:
        Object(mia::string name = "unnamed");
    public:
        virtual ~Object();
    #pragma endregion

    #pragma region Attribute
    protected:
        mia::string _name;
        bool _active;
        uint32_t _tag;
        Object *_parent;
        int _scene;
    #pragma endregion

    #pragma region Get-method
    public:
        mia::string name() const;
        bool isActive() const;
        uint32_t getTag() const;
        const Object* parent() const;
        int getScene() const;
    #pragma endregion

    #pragma region Set-method
    public:
        mia::string& name();
        Object* parent();
    #pragma endregion

    #pragma region Public method
    public:
        bool SetActive(bool newState);
        bool IsContainTag(int tag);
        uint32_t AddTag(int tag);
        uint32_t RemoveTag(int tag);
    #pragma endregion

    #pragma region Inherited method
    public:
        const char* ToStr() const override;
    #pragma endregion
    };
}

#endif