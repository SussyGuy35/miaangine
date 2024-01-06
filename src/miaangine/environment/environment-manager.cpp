#include "environment-manager.hpp"

namespace mia
{
    std::shared_ptr<ObjectContainer> Environment::container = std::make_shared<ObjectContainer>();

    Object* Environment::Create(Vector2 _position)
    {
        Object* _instance = new Object(_position);

        container->AddObject(_instance);
        return _instance;
    }
    Object* Environment::Create(float _x, float _y)
    {
        Object* _instance = new Object(_x, _y);

        container->AddObject(_instance);
        return _instance;
    }
}