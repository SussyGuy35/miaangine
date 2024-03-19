#include "image-renderer.hpp"

#include "core/engine-components.hpp"

#include <algorithm>

namespace mia 
{
    ImageRenderer::ImageRenderer()
    {}

    ImageRenderer::~ImageRenderer()
    {}

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
        for (Image *image : _images)
        {
            SDL_Texture* texture = image->texture();
            int w = 0, h = 0;
            if (SDL_QueryTexture(texture, NULL, NULL, &w, &h)) 
            {
                debug.Warning("[PortraitRender] Failed to load texture {%s} of [Image(%s)]; Ignore. ", image->textureDirectory().str(), image->name().str());
                continue;
            }

            SDL_SetTextureColorMod(texture, image->color().r, image->color().b, image->color().g);
            SDL_SetTextureAlphaMod(texture, image->color().a);
            
            SDL_Rect rect = RectRenderingCalculate(image);

            SDL_RenderCopy(renderer, texture, NULL, &rect);
        }
    }

    SDL_Rect ImageRenderer::RectRenderingCalculate(Image *image)
    {
        SDL_Rect rect;

        rect.x = static_cast<int>(image->position().x + image->offset().x);
        rect.y = static_cast<int>(image->position().y + image->offset().y);
        rect.w = static_cast<int>(image->size().x);
        rect.h = static_cast<int>(image->size().y);

        return rect;
    }
}