#ifndef _MIA_RENDERER_HPP
#define _MID_RENDERER_HPP

#include <memory>

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
    
    public:
        std::unique_ptr<PortraitRenderer> portraitHandle;
        std::unique_ptr<ImageRenderer> imageHandle;

        void Render(SDL_Renderer *renderer);
    };
}

#endif