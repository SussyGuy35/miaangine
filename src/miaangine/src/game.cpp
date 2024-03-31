#include "game.hpp"

#include "input.hpp"

namespace mia
{
    Game::Game()
    {}

    Game::~Game()
    {}

    int Game::InitWindow()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) 
        {
            return -1;
        }

        window = SDL_CreateWindow(
            "",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
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

        _windowWidth = WINDOW_WIDTH;
        _windowHeight = WINDOW_HEIGHT;

        return 0;
    }

    int Game::getWindowWidth() const
    {
        return _windowWidth;
    }
    int Game::getWindowHeight() const
    {
        return _windowHeight;
    }

    int Game::ClearWindow()
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        IMG_Quit();
        SDL_Quit();
    }

    int Game::Step()
    {
        Input::Instance().Update();
    }
}