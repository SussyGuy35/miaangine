#ifndef _MIA_PORTRAIT_RENDERER_HPP
#define _MIA_PORTRAIT_RENDERER_HPP

#include "util/singleton.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "component/sprite.hpp"

namespace mia 
{
    class PortraitRenderer : public Singleton<PortraitRenderer>
    {
    private:
        friend class Singleton<PortraitRenderer>;
        PortraitRenderer();
        ~PortraitRenderer();

    private:
        std::vector<Sprite*> _sprites;

    public:
        void RegisterPortrait(Sprite *portrait);
        void RemovePortrait(Sprite *portrait);

        void Render(SDL_Renderer *renderer);

    private:
        SDL_Rect RectRenderingCalculate(SDL_Texture *_texture, int w, int h);
    };
}

#endif