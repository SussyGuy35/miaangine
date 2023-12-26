#ifndef _MIA_SDL_INIT_HPP
#define _MIA_SDL_INIT_HPP

#include <SDL.h>

namespace mia
{
    class InitSDL
    {
    public:
        InitSDL(uint32_t _width, uint32_t _height, bool _fullscreen);

        void Init();
        void Clean();

    private:
        uint32_t m_width;
        uint32_t m_height;
        bool m_fullscreen;
        
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
    };
}

#endif