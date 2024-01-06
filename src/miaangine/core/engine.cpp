#include "engine.hpp"

namespace mia
{
    Engine::Engine(): 
        state(std::make_shared<GameState>()),
        timer(std::make_shared<Timer>()),
        loop(std::make_shared<GameLoop>()),
        renderer(std::make_shared<Renderer>()),
        sdl(std::make_unique<SDLHandle>(800, 600, false))
    {
        
    }

    Engine::~Engine()
    {
        
    }

    int Engine::Init()
    {
        sdl->Init();

        return 0;
    }

    int Engine::Exit()
    {
        sdl->Clear();

        delete(this);
  
        return 0;
    }
}