#ifndef _MIA_SDL_HANDLE_HPP
#define _MIA_SDL_HANDLE_HPP

#include <SDL.h>

namespace mia
{
    class SDLHandle
    {
    public:
        SDLHandle(uint32_t _width, uint32_t _height, bool _fullscreen);

        bool Init();
        void Clear();

        SDL_Window *window;
        SDL_Renderer *renderer;

    private:
        uint32_t m_width;
        uint32_t m_height;
        bool m_fullscreen;
    };
}

#endif