#ifndef _MIA_SDL_HANDLE_HPP
#define _MIA_SDL_HANDLE_HPP

#include <SDL.h>

namespace mia
{
    class SDLHandle
    {
    private:
        static SDLHandle *__instance;
    public:
        static SDLHandle* Instance() 
        {
            if (!__instance) __instance = new SDLHandle(); 
            return __instance;
        }

        SDLHandle(const SDLHandle&) = delete;
        void operator=(const SDLHandle&) = delete;

    private:
        SDLHandle();
    
    public:
        ~SDLHandle();

    public:
        SDL_Window *window;
        SDL_Renderer *renderer;

        bool Init(uint32_t width, uint32_t height, bool fullscreen);
        void Clear();
    };
}

#endif