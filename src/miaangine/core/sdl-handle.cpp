#include "sdl-handle.hpp"

namespace mia
{
    SDLHandle::SDLHandle(uint32_t _width, uint32_t _height, bool _fullscreen):
        m_width(_width),
        m_height(_height),
        m_fullscreen(_fullscreen)
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
            m_width, 
            m_height, 
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
}