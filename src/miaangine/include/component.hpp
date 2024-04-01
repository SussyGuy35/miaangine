#ifndef _MIA_COMPONENT_HPP
#define _MIA_COMPONENT_HPP

#include "transform.hpp"

namespace mia
{
    class Component : public Entity
    {
    public:
        Component();
        virtual ~Component();

    protected:
        bool _active;
        Transform *_master;

    public:
        bool isActive() const;
        const Transform* master() const;

        virtual bool SetActive(bool newState);
        virtual Transform* SetMaster(Transform* newMaster);

        virtual bool Init() = 0;

    public:
        const char* ToStr() const override;
    };
}

#endif