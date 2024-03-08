#include "portrait-renderer.hpp"

#include <SDL.h>
#include <algorithm>

#include "core/camera.hpp"

namespace mia 
{
    PortraitRenderer *PortraitRenderer::__instance = nullptr;

    PortraitRenderer::PortraitRenderer()
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

    void PortraitRenderer::Log() //TODO
    {
        SDL_Log("%.2f - %llu | "
                "PortraitRenderer > Portrait Count(%d)",
                Time::time, Time::stepCount,
                _portraits.size());
    }

    SDL_Rect PortraitRenderer::RectRenderingCalculate(const Portrait *portrait)
    {
        SDL_Rect rect;

        rect.x = static_cast<int>(portrait->position->x + portrait->offset.x - Camera::position.x);
        rect.y = static_cast<int>(Camera::position.y + Camera::SCREEN_HEIGHT - portrait->position->y - portrait->offset.y - portrait->size.y); //FIXME
        rect.w = static_cast<int>(portrait->size.x);
        rect.h = static_cast<int>(portrait->size.y);

        return rect;
    }
}