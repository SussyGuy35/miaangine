#include "sdl-handle.hpp"

#include <stdio.h>

#include "time/time-manager.hpp"

namespace mia
{
    SDLHandle *SDLHandle::__instance = nullptr;

    SDLHandle::SDLHandle():
        _width(0),
        _height(0),
        _fullscreen(0)
    {}

    SDLHandle::~SDLHandle()
    {
        __instance = nullptr;
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
    }

    bool SDLHandle::Init(uint32_t width, uint32_t height, bool fullscreen)
    {
        _width = width;
        _height = height;
        _fullscreen = fullscreen;

        if(SDL_Init(SDL_INIT_VIDEO) < 0) return false;

        // Create window
        window = SDL_CreateWindow( 
            "MIAANGINE", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            _width, 
            _height, 
            SDL_WINDOW_OPENGL
        );
        if (window == NULL) return false;

        renderer = SDL_CreateRenderer(
            window, 
            -1, 
            SDL_RENDERER_ACCELERATED
        );
        if (renderer == NULL) return false;

        return true;
    }

    void SDLHandle::Clear()
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
    }

    // void SDLHandle::Log() //TODO
    // {
    //     SDL_Log("%.2f - %llu | "
    //             "SDLHandle > Screen: Width(%u); Height (%u); Fullscreen(%d)",
    //             TimeManager::time, TimeManager::stepCount,
    //             _width, _height, _fullscreen);
    // }
}