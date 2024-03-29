#ifndef _MIA_ENTITY_HPP
#define _MIA_ENTITY_HPP

namespace mia
{
    class Entity
    {
    public:
        int ID;
        bool active;

        Entity():
            ID(0),
            active(false)
        {}
        
        virtual ~Entity()
        {}

        virtual void ToString() = 0;
    };
}

#endif