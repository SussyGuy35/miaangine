#include "portrait-renderer.hpp"

#include "core/engine-components.hpp"

#include <algorithm>

namespace mia 
{
    PortraitRenderer::PortraitRenderer()
    {}

    PortraitRenderer::~PortraitRenderer()
    {}

    void PortraitRenderer::RegisterPortrait(Portrait *portrait)
    {
        _portraits.push_back(portrait);
    }

    void PortraitRenderer::RemovePortrait(Portrait *portrait)
    {
        auto listenerIterator = std::find(_portraits.begin(), _portraits.end(), portrait);

        if (listenerIterator != _portraits.end())
        {
            _portraits.erase(listenerIterator);
        }
    }

    void PortraitRenderer::Render(SDL_Renderer *renderer)
    {
        for (Portrait *portrait : _portraits)
        {
            SDL_Texture* texture = portrait->texture();
            int w = 0, h = 0;
            if (SDL_QueryTexture(texture, NULL, NULL, &w, &h)) 
            {
                debug.Error("[PortraitRender] Failed to load texture {%s}", portrait->textureDirectory().str()); //FIXME
                continue;
            }

            SDL_SetTextureColorMod(texture, portrait->color().r, portrait->color().b, portrait->color().g);
            SDL_SetTextureAlphaMod(texture, portrait->color().a);
            
            SDL_Rect rect = RectRenderingCalculate(portrait, w, h);

            SDL_RenderCopy(renderer, texture, NULL, &rect);
        }
    }

    SDL_Rect PortraitRenderer::RectRenderingCalculate(Portrait *portrait, int w, int h)
    {
        SDL_Rect rect;

        float displayW = 1.0 * w * portrait->scale().x * generic.PORTRAIT_PIXEL_SCALE;
        float displayH = 1.0 * h * portrait->scale().y * generic.PORTRAIT_PIXEL_SCALE;

        rect.x = static_cast<int>(portrait->position().x + portrait->offset().x - camera.position.x);
        rect.y = static_cast<int>(camera.position.y + generic.windowHeight - portrait->position().y - portrait->offset().y - displayH);
        rect.w = static_cast<int>(displayW);
        rect.h = static_cast<int>(displayH);

        return rect;
    }
}