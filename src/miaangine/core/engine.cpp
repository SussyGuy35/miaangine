#include "engine.hpp"

namespace mia
{
    Engine::Engine(): 
        state(std::make_shared<GameState>()),
        timer(std::make_shared<Timer>()),
        loop(std::make_shared<GameLoop>()),
        m_initSDL(std::make_unique<InitSDL>(800, 600, false))
    {
        
    }

    Engine::~Engine()
    {
        
    }

    int Engine::Init()
    {
        m_initSDL->Init();

        return 0;
    }

    int Engine::Exit()
    {
        m_initSDL->Clean();

        delete(this);
  
        return 0;
    }
}