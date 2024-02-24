#ifndef _MIA_PORTRAIT_RENDERER_HPP
#define _MIA_PORTRAIT_RENDERER_HPP

#include <vector>

#include "portrait.hpp"

namespace mia 
{
    class PortraitRenderer
    {
    public:
        PortraitRenderer() {}

    private:
        std::vector<Portrait *> _portraits;

    public:
        void RegisterPortrait(Portrait *portrait);
        void RemovePortrait(Portrait *portrait);

        void RenderPotraits();
    };
}

#endif