#include "renderer.hpp"

namespace mia
{
    Renderer::Renderer():
        _portraitHandle(PortraitRenderer::Instance()),
        _imageHandle(ImageRenderer::Instance())
    {}

    Renderer::~Renderer()
    {}

    void Renderer::RegisterPortrait(Portrait *portrait)
    {
        _portraitHandle.RegisterPortrait(portrait);
    }
    void Renderer::RemovePortrait(Portrait *portrait)
    {
        _portraitHandle.RemovePortrait(portrait);
    }

    void Renderer::RegisterImage(Image *image)
    {
        _imageHandle.RegisterImage(image);
    }
    void Renderer::RemoveImage(Image *image)
    {
        _imageHandle.RemoveImage(image);
    }

    void Renderer::Render(SDL_Renderer *renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        _portraitHandle.Render(renderer);
        _imageHandle.Render(renderer);

        SDL_RenderPresent(renderer);
    }
}