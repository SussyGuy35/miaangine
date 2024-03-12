#ifndef _MIA_PORTRAIT_RENDERER_HPP
#define _MIA_PORTRAIT_RENDERER_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "portrait.hpp"

namespace mia 
{
    class PortraitRenderer
    {
    private:
        static PortraitRenderer *__instance;
    public:
        static PortraitRenderer* Instance() 
        {
            if (!__instance) __instance = new PortraitRenderer(); 
            return __instance;
        }

        PortraitRenderer(const PortraitRenderer&) = delete;
        void operator=(const PortraitRenderer&) = delete;
    
    private:
        PortraitRenderer();

    public:
        ~PortraitRenderer();

    private:
        std::vector<Portrait*> _portraits;

    public:
        void RegisterPortrait(Portrait *portrait);
        void RemovePortrait(Portrait *portrait);

        void Render(SDL_Renderer *renderer);

    private:
        SDL_Rect RectRenderingCalculate(const Portrait *portrait);
    };
}

#endif