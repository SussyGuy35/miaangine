#ifndef _MIA_PORTRAIT_RENDERER_HPP
#define _MIA_PORTRAIT_RENDERER_HPP

#include <SDL.h>
#include <SDL_image.h>

#include <vector>

#include "util/singleton.hpp"

#include "portrait.hpp"

namespace mia 
{
    class PortraitRenderer : public Singleton<PortraitRenderer>
    {
    private:
        friend class Singleton<PortraitRenderer>;
        PortraitRenderer();
        ~PortraitRenderer();

    private:
        std::vector<Portrait*> _portraits;

    public:
        void RegisterPortrait(Portrait *portrait);
        void RemovePortrait(Portrait *portrait);

        void Render(SDL_Renderer *renderer);

    private:
        SDL_Rect RectRenderingCalculate(Portrait *portrait);
    };
}

#endif