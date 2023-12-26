#ifndef _MIA_ENGINE_HPP
#define _MIA_ENGINE_HPP

#include "engine-forward.hpp"

#include <memory>

#include "game-state.hpp"
#include "timer.hpp"

#include "init/sdl-init.hpp"

#include "input/input-manager.hpp"

// namespace mia
// {
    class mia::Engine
    {
    public:
        Engine();
        ~Engine();

        int Init();
        int Exit();

    private:
        std::shared_ptr<GameState> m_gameState;
        std::shared_ptr<Timer> m_timer;

        std::unique_ptr<InitSDL> m_initSDL;

    public:
        uint8_t GetGameState() const;
        uint8_t SetGameState(uint8_t _state);
    };
// }

#endif