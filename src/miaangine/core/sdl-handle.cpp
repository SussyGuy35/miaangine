#include "sdl-handle.hpp"

#include <stdio.h>

#include "time.hpp"

namespace mia
{
    SDLHandle::SDLHandle(uint32_t _width, uint32_t _height, bool _fullscreen):
        _width(_width),
        _height(_height),
        _fullscreen(_fullscreen)
    {

    }

    bool SDLHandle::Init()
    {
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

    void SDLHandle::Log()
    {
        SDL_Log(":: %f : %llu ::\n"
                "SDLHandle > Screen: Width(%u); Height (%u); Fullscreen(%d)\n<>",
                Time::time, Time::stepCount,
                _width, _height, _fullscreen);
    }
}