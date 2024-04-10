#ifndef _MIA_RENDERER_HPP
#define _MIA_RENDERER_HPP

#include "common.hpp"

#include "portrait.hpp"

namespace mia
{
    class Renderer : public Singleton<Renderer>
    {
    private:
        friend class Singleton<Renderer>;
        Renderer();
        ~Renderer();

    private:
        std::vector<Portrait*> _portraitsList;

        bool _renderBodies;

    public:
        void RegisterPortrait(Portrait *portrait);
        void UnregisterPortrait(Portrait *portrait);

        const std::vector<Portrait*> GetPortraitssList();

        void Render(SDL_Renderer *renderer);

        void SetRenderBodies(bool state);

    private:
        void RenderPortraits(SDL_Renderer *renderer);
        void RenderBodyRects(SDL_Renderer *renderer);

        SDL_Rect PortraitRectCalculate(Portrait &portrait);
    };
}

#endif