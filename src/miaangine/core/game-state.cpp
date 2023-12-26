#include "game-state.hpp"

namespace mia 
{
    GameState::GameState():
        m_state(0)
    {

    }

    GameState::~GameState()
    {

    }

    uint8_t GameState::GetState() const
    {
        return m_state;
    }

    void GameState::SetState(uint8_t _state)
    {
        m_state = _state;
    }
}