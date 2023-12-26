#ifndef _MIA_GAME_STATE_HPP
#define _MIA_GAME_STATE_HPP

#include <stdint.h>

namespace mia
{
    class GameState
    {
    /*
        0: Running
        1: Pause
        2: Exit
    */

    public:
        GameState();
        ~GameState();
    
    private:
        uint8_t m_state;

    public:
        uint8_t GetState() const;

        void SetState(uint8_t _state);
    };
}

#endif