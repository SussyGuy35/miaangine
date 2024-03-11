#include "renderer.hpp"

namespace mia
{
    Renderer *Renderer::__instance = nullptr;

    Renderer::Renderer():
        portraitHandle(PortraitRenderer::Instance())
    {}

    Renderer::~Renderer()
    {
        __instance = nullptr;
    }

    void Renderer::Render(SDL_Renderer *renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        portraitHandle->RenderPotraits(renderer);

        SDL_RenderPresent(renderer);
    }
}