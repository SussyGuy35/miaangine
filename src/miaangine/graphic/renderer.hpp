#ifndef _MIA_RENDERER_HPP
#define _MID_RENDERER_HPP

#include "util/singleton.hpp"

#include "portrait-renderer.hpp"
#include "image-renderer.hpp"

namespace mia
{
    class Renderer : public Singleton<Renderer>
    {
    private:
        friend class Singleton<Renderer>;
        Renderer();
        ~Renderer();
    
    private:
        PortraitRenderer &_portraitHandle;
        ImageRenderer &_imageHandle;

    public:
        void RegisterPortrait(Portrait *portrait);
        void RemovePortrait(Portrait *portrait);

        void RegisterImage(Image *image);
        void RemoveImage(Image *image);

        void Render(SDL_Renderer *renderer);
    };
}

#endif