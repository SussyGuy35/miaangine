#include "engine.hpp"

namespace mia
{
    Engine::Engine(): 
        m_gameState(std::make_shared<GameState>()),
        m_timer(std::make_shared<Timer>()),
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

    uint8_t Engine::GetGameState() const 
    {
        return m_gameState->GetState();
    }

    uint8_t Engine::SetGameState(uint8_t _state)
    {
        m_gameState->SetState(_state);
        return _state;
    }
}