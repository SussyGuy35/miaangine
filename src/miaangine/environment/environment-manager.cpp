#include "environment-manager.hpp"

namespace mia
{
    std::shared_ptr<ObjectContainer> Environment::container = std::make_shared<ObjectContainer>();

    Object* Environment::Create()
    {
        Object* _instance = new Object();

        container->AddObject(_instance);
        return _instance;
    }
}