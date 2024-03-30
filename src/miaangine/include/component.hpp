#ifndef _MIA_COMPONENT_HPP
#define _MIA_COMPONENT_HPP

#include "object.hpp"

namespace mia
{
    class mia::Component : public Entity
    {
    public:
        Component();
        virtual ~Component();

    protected:
        bool _active;
        Object *_master;

    public:
        bool isActive() const;
        const Object* master() const;

        virtual bool SetActive(bool newState);
        virtual Object* SetMaster(Object* newMaster);

    public:
        const char* ToStr() const override;
    };
}

#endif