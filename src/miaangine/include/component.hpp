#ifndef _MIA_COMPONENT_HPP
#define _MIA_COMPONENT_HPP

#include "object.hpp"

namespace mia
{
    class mia::Component : public Entity
    {
    #pragma region Contructor Destructor
    protected:
        Component();
    public:
        virtual ~Component();
    #pragma endregion

    #pragma region Attribute
    protected:
        bool _active;
        Object *_master;
    #pragma endregion

    #pragma region Get-method
    public:
        bool isActive() const;
        const Object* master() const;
    #pragma endregion

    #pragma region Set-method
    public:
        bool SetActive();
        Object* SetMaster();
    #pragma endregion

    #pragma region Inherited method
    public:
        const char* ToStr() const override;
    #pragma endregion
    };
}

#endif