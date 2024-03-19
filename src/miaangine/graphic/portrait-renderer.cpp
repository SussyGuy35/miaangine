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
            if (portrait->textureDirectory() == string::empty())
            {
                SDL_Rect rect = RectRenderingCalculate(portrait, PIXEL_PER_UNIT, PIXEL_PER_UNIT);

                SDL_SetRenderDrawColor(renderer, portrait->color().r, portrait->color().b, portrait->color().g, portrait->color().a);
                SDL_RenderFillRect(renderer, &rect);

                continue;
            }

            SDL_Texture* texture = portrait->texture();
            int w = 0, h = 0;
            if (SDL_QueryTexture(texture, NULL, NULL, &w, &h) != 0) 
            {
                debug.Error("[PortraitRender] Failed to load texture {%s} of [Portrait(%s)]; Ignore. ", portrait->textureDirectory().str(), portrait->name().str());
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

        float unitSize = (generic.windowWidth / camera.size());

        float displayW = 1.0 * w * portrait->scale().x * unitSize / PIXEL_PER_UNIT;
        float displayH = 1.0 * h * portrait->scale().y * unitSize / PIXEL_PER_UNIT;
        float displayX = (portrait->position().x + portrait->offset().x - camera.position().x) * unitSize;
        float displayY = generic.windowHeight - displayH - (portrait->position().y + portrait->offset().y - camera.position().y) * unitSize;

        //FIXME
        rect.x = static_cast<int>(displayX);
        rect.y = static_cast<int>(displayY); 
        rect.w = static_cast<int>(displayW);
        rect.h = static_cast<int>(displayH);

        return rect;
    }
}