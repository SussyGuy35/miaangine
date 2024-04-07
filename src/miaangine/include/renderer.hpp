#ifndef _MIA_RENDERER_HPP
#define _MIA_RENDERER_HPP

#include "common.hpp"
#include <functional>
#include "Quadtree.h"

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
        std::function<quadtree::Box<float>(Portrait* p)> getBox;

        quadtree::Quadtree<Portrait*, decltype(getBox)> _portraitTree;

        decltype(getBox) a = getBox;

    public:
        void RegisterPortrait(Portrait *portrait);
        // void RemovePortrait(Portrait *portrait); //TODO

        void Render(SDL_Renderer *renderer);

    private:
        void RenderPortraits(SDL_Renderer *renderer);

        SDL_Rect PortraitRectCalculate(Portrait &portrait);
    };
}

#endif