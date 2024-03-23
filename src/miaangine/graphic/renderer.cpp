#include "renderer.hpp"

namespace mia
{
    Renderer::Renderer():
        _spriteHandle(SpriteRenderer::Instance())
    {}

    Renderer::~Renderer()
    {}

    void Renderer::RegisterSprite(Sprite *sprite)
    {
        _spriteHandle.RegisterSprite(sprite);
    }
    void Renderer::RemoveSprite(Sprite *sprite)
    {
        _spriteHandle.RemoveSprite(sprite);
    }

    void Renderer::Render(SDL_Renderer *renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        _spriteHandle.Render(renderer);

        SDL_RenderPresent(renderer);
    }
}