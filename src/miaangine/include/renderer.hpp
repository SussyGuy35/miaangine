#ifndef _MIA_RENDERER_HPP
#define _MIA_RENDERER_HPP

#include "common.hpp"

#include <functional>
#include "Quadtree/Quadtree.h"

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
        std::function<quadtree::Box<float>(Portrait* p)> _getBox;
        quadtree::Quadtree<Portrait*, decltype(_getBox)> _portraitTree;

    public:
        void RegisterPortrait(Portrait *portrait);
        void RemovePortrait(Portrait *portrait);

        void Render(SDL_Renderer *renderer);

    private:
        void RenderPortraits(SDL_Renderer *renderer);

        SDL_Rect PortraitRectCalculate(Portrait &portrait);
    };
}

#endif