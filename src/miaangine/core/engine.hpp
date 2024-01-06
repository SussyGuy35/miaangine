#ifndef _MIA_ENGINE_HPP
#define _MIA_ENGINE_HPP

#include <memory>

#include "game-state.hpp"
#include "timer.hpp"
#include "game-loop.hpp"
#include "renderer.hpp"
#include "sdl-handle.hpp"

#include "input/input-manager.hpp"

namespace mia
{
    class Engine
    {
    public:
        Engine();
        ~Engine();

        int Init();
        int Exit();

    public:
        std::shared_ptr<GameState> state;
        std::shared_ptr<Timer> timer;
        std::shared_ptr<GameLoop> loop;
        std::shared_ptr<Renderer> renderer;
        std::shared_ptr<SDLHandle> sdl;
    };
}

#endif