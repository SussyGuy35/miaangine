#include "game.hpp"

#include "event-dispatcher.hpp"
#include "time.hpp"
#include "camera.hpp"
#include "input.hpp"
#include "physics.hpp"
#include "renderer.hpp"

namespace mia
{
    Game::Game()
    {}

    Game::~Game()
    {}

    int Game::
    InitWindow()
    {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0) 
        {
            return -1;
        }

        window = SDL_CreateWindow(
            "",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            INIT_WINDOW_WIDTH,
            INIT_WINDOW_HEIGHT,
            SDL_WINDOW_SHOWN
        );
        if (window == NULL) 
        {
            SDL_Quit();
            return -1;
        }

        renderer = SDL_CreateRenderer(
            window, 
            -1, 
            SDL_RENDERER_ACCELERATED
        );
        if (renderer == NULL) 
        {
            SDL_Quit();
            return -1;
        }
    
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags)) 
        {
            SDL_Quit();
            return -1;
        }

        TTF_Init();

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        {
            SDL_Quit();
            return -1;
        }

        Camera::Instance()._screenWidth = INIT_WINDOW_WIDTH;
        Camera::Instance()._screenHeight = INIT_WINDOW_HEIGHT;

        return 0;
    }

    int Game::ClearWindow()
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        IMG_Quit();
        TTF_Quit();
        Mix_Quit();
        SDL_Quit();
    }

    int Game::Update()
    {
        EventDispatcher::Instance().Notify(_EVENT_ON_ENTER_FRAME);

        Time::Instance().Step();

        Input::Instance().Update();

        EventDispatcher::Instance().Notify(_EVENT_PRIMARY_UPDATE);

        Physics::Instance().Update(Time::Instance().deltaTime());

        return 0;
    }

    int Game::Render()
    {
        Renderer::Instance().Render(renderer);

        return 0;
    }
}