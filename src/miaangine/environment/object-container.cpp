#include "object-container.hpp"

namespace mia
{
    ObjectContainer::ObjectContainer()
    {

    }

    ObjectContainer::~ObjectContainer()
    {

    }

    void ObjectContainer::AddObject(Object* _object)
    {
        objectList.push_back(_object);
    }

    void ObjectContainer::RemoveObject(Object* _object)
    {
        
    }
}