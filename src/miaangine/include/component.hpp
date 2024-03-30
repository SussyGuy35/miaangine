#ifndef _MIA_COMPONENT_HPP
#define _MIA_COMPONENT_HPP

#include "object.hpp"

namespace mia
{
    class mia::Component : public Entity
    {
    protected:
        Component();
    public:
        virtual ~Component();

    protected:
        bool _active;
        Object *_master;

    public:
        bool isActive() const;
        const Object* master() const;

        bool SetActive();
        Object* SetMaster();

    public:
        const char* ToStr() const override;
    };
}

#endif