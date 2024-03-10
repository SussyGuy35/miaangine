#include "portrait-renderer.hpp"

#include <SDL.h>
#include <algorithm>

#include "core/camera.hpp"

#include "core/engine.hpp"
#include "time/time-manager.hpp"

namespace mia 
{
    PortraitRenderer *PortraitRenderer::__instance = nullptr;

    PortraitRenderer::PortraitRenderer()
    {}

    PortraitRenderer::~PortraitRenderer()
    {
        __instance = nullptr;
    }

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

    void PortraitRenderer::RenderPotraits(SDL_Renderer *renderer)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (const Portrait *portrait : _portraits)
        {
            SDL_Rect rect = RectRenderingCalculate(portrait);

            SDL_SetRenderDrawColor(renderer, portrait->color.r, portrait->color.b, portrait->color.g, portrait->color.a);
            SDL_RenderFillRect(renderer, &rect);
        }

        SDL_RenderPresent(renderer);
    }

    SDL_Rect PortraitRenderer::RectRenderingCalculate(const Portrait *portrait)
    {
        SDL_Rect rect;

        rect.x = static_cast<int>(portrait->position->x + portrait->offset.x - Camera::position.x);
        rect.y = static_cast<int>(Camera::position.y + windowHeight - portrait->position->y - portrait->offset.y - portrait->size.y);
        rect.w = static_cast<int>(portrait->size.x);
        rect.h = static_cast<int>(portrait->size.y);

        return rect;
    }
}