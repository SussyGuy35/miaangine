#ifndef _MIA_RENDERER_HPP
#define _MID_RENDERER_HPP

#include "util/singleton.hpp"

#include "sprite-renderer.hpp"

namespace mia
{
    class Renderer : public Singleton<Renderer>
    {
    private:
        friend class Singleton<Renderer>;
        Renderer();
        ~Renderer();
    
    private:
        SpriteRenderer &_spriteHandle;

    public:
        void RegisterSprite(Sprite *sprite);
        void RemoveSprite(Sprite *sprite);

        void Render(SDL_Renderer *renderer);
    };
}

#endif