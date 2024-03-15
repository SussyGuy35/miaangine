#include "image-renderer.hpp"

#include "core/engine-components.hpp"

#include <algorithm>

namespace mia 
{
    ImageRenderer *ImageRenderer::__instance = nullptr;

    ImageRenderer::ImageRenderer()
    {}

    ImageRenderer::~ImageRenderer()
    {
        __instance = nullptr;
    }

    void ImageRenderer::RegisterImage(Image *image)
    {
        _images.push_back(image);
    }

    void ImageRenderer::RemoveImage(Image *image)
    {
        auto listenerIterator = std::find(_images.begin(), _images.end(), image);

        if (listenerIterator != _images.end())
        {
            _images.erase(listenerIterator);
        }
    }

    void ImageRenderer::Render(SDL_Renderer *renderer)
    {
        for (const Image *image : _images)
        {
            SDL_Rect rect = RectRenderingCalculate(image);

            SDL_SetRenderDrawColor(renderer, image->color.r, image->color.b, image->color.g, image->color.a);
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    SDL_Rect ImageRenderer::RectRenderingCalculate(const Image *image)
    {
        SDL_Rect rect;

        rect.x = static_cast<int>(image->position->x + image->offset.x);
        rect.y = static_cast<int>(image->position->y + image->offset.y);
        rect.w = static_cast<int>(image->size.x);
        rect.h = static_cast<int>(image->size.y);

        return rect;
    }
}