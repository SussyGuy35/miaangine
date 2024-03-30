#ifndef _MIA_OBJECT_HPP
#define _MIA_OBJECT_HPP

#include "entity.hpp"

namespace mia
{
    class Component;

    class Object : public Entity
    {
    #pragma region Contructor Destructor
    public:
        Object(const char *name = "unnamed");
        virtual ~Object();
    #pragma endregion

    #pragma region Attribute
    protected:
        mia::string _name;
        bool _active;
        uint32_t _tag;
        int _scene;
    #pragma endregion

    #pragma region Get-method
    public:
        mia::string name() const;
        bool isActive() const;
        uint32_t getTag() const;
        int getScene() const;
    #pragma endregion

    #pragma region Set-method
    public:
        mia::string& name();
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