#ifndef _MIA_SPRITE_RENDERER_HPP
#define _MIA_SPRITE_RENDERER_HPP

#include "util/singleton.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "component/sprite.hpp"

namespace mia 
{
    class SpriteRenderer : public Singleton<SpriteRenderer>
    {
    private:
        friend class Singleton<SpriteRenderer>;
        SpriteRenderer();
        ~SpriteRenderer();

    private:
        std::vector<Sprite*> _sprites;

    public:
        void RegisterSprite(Sprite *sprite);
        void RemoveSprite(Sprite *sprite);

        void Render(SDL_Renderer *renderer);

    private:
        SDL_Rect RectRenderingCalculate(Sprite *sprite, int w, int h);
    };
}

#endif