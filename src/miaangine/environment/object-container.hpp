#ifndef _MIA_OBJECT_CONTAINER_HPP
#define _MIA_OBJECT_CONTAINER_HPP

#include <list>

#include "object-forward.hpp"

namespace mia 
{
    class ObjectContainer 
    {
    public:
        ObjectContainer();
        ~ObjectContainer();

    public:
        std::list<Object*> objectList;

    public:
        void AddObject(Object* _object);
        void RemoveObject(Object* _object);
    };
}

#endif