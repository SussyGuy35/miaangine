#include "game-loop.hpp"

#include <iostream>

#include "environment/environment-manager.hpp"

namespace mia
{
    GameLoop::GameLoop()
    {

    }

    GameLoop::~GameLoop()
    {
        
    }

    void GameLoop::Start()
    {
        for (Object* _object : Environment::container->objectList)
        {
            _object->Start();
        }
    }

    void GameLoop::Update()
    {
        for (Object* _object : Environment::container->objectList)
        {
            _object->Update();
        }
    }
}