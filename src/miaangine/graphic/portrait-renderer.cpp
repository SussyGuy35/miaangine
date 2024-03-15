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
            SDL_Rect rect = RectRenderingCalculate(portrait);

            SDL_SetRenderDrawColor(renderer, portrait->color.r, portrait->color.b, portrait->color.g, portrait->color.a);
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    SDL_Rect PortraitRenderer::RectRenderingCalculate(Portrait *portrait)
    {
        SDL_Rect rect;

        rect.x = static_cast<int>(portrait->position().x + portrait->offset.x - camera.position.x);
        rect.y = static_cast<int>(camera.position.y + generic.windowHeight - portrait->position().y - portrait->offset.y - portrait->size.y);
        rect.w = static_cast<int>(portrait->size.x);
        rect.h = static_cast<int>(portrait->size.y);

        return rect;
    }
}