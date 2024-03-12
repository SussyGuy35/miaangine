#include "renderer.hpp"

#include <SDL_image.h> //FIXME

namespace mia
{
    Renderer *Renderer::__instance = nullptr;

    Renderer::Renderer():
        portraitHandle(PortraitRenderer::Instance()),
        imageHandle(ImageRenderer::Instance())
    {}

    Renderer::~Renderer()
    {
        __instance = nullptr;
    }

    void Renderer::Render(SDL_Renderer *renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        portraitHandle->Render(renderer);
        imageHandle->Render(renderer);

        SDL_RenderPresent(renderer);
    }
}