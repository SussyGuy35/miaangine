#ifndef _MIA_COMPONENT_HPP
#define _MIA_COMPONENT_HPP

#include "object.hpp"

namespace mia
{
    class mia::Component : public Entity
    {
    public:
    #pragma region Contructor Destructor
        Component();
        ~Component();
    #pragma endregion

    protected:
    #pragma region Attribute
        bool _active;
        Object *_master;
    #pragma endregion

    public:
    #pragma region Get-method
        bool isActive() const;
        const Object* master() const;
    #pragma endregion

    #pragma region Set-method
        bool SetActive();
        Object* SetMaster();
    #pragma endregion

    #pragma region Inherited method
        const char* ToStr() const override;
    #pragma endregion
    };
}

#endif