#ifndef _MIA_SDL_HANDLE_HPP
#define _MIA_SDL_HANDLE_HPP

#include <SDL.h>

namespace mia
{
    class SDLHandle
    {
    public:
        SDLHandle();

    private:
        uint32_t _width;
        uint32_t _height;
        bool _fullscreen;

    public:
        SDL_Window *window;
        SDL_Renderer *renderer;

        bool Init(uint32_t width, uint32_t height, bool fullscreen);
        void Clear();

        void Log();
    };
}

#endif