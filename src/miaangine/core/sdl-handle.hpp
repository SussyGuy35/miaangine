#ifndef _MIA_SDL_HANDLE_HPP
#define _MIA_SDL_HANDLE_HPP

#include <SDL.h>
#include <SDL_image.h>

#include "util/singleton.hpp"

namespace mia
{
    class SDLHandle : public Singleton<SDLHandle>
    {
    private:
        friend class Singleton<SDLHandle>;
        SDLHandle();
        ~SDLHandle();

    public:
        SDL_Window *window;
        SDL_Renderer *renderer;

        bool Init(uint32_t width, uint32_t height, bool fullscreen);
        void Clear();
    };
}

#endif