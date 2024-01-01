#include "game-loop.hpp"

#include <iostream>

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
        std::cout << "Start" << std::endl;
    }

    void GameLoop::Update()
    {
        std::cout << "Update" << std::endl;
    }
}