#include "sdl-init.hpp"

namespace mia
{
    InitSDL::InitSDL(uint32_t _width, uint32_t _height, bool _fullscreen)
    {
        m_width = _width;
        m_height = _height;
        m_fullscreen = _fullscreen;
    }

    void InitSDL::Init()
    {
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) return;

		m_window = SDL_CreateWindow("PHYSICS ENGINE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, 0);
		if (m_window == nullptr) return;

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (m_renderer == nullptr) return;
    }

    void InitSDL::Clean()
    {
        SDL_DestroyWindow(m_window);
        SDL_DestroyRenderer(m_renderer);
    }
}