#include "portrait-renderer.hpp"

#include <algorithm>

#include "core/engine.hpp"

namespace mia 
{
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

    void PortraitRenderer::RenderPotraits()
    {
        SDL_SetRenderDrawColor(sdlHandle->renderer, 0, 0, 0, 255);
        SDL_RenderClear(sdlHandle->renderer);

        for (const Portrait *portrait : _portraits)
        {
            SDL_Rect rect;
            rect.x = portrait->master->position.x + portrait->offset.x;
            rect.y = portrait->master->position.y + portrait->offset.x;
            rect.w = portrait->size.x;
            rect.h = portrait->size.y;

            SDL_SetRenderDrawColor(sdlHandle->renderer, portrait->color.r, portrait->color.b, portrait->color.g, portrait->color.a);
            SDL_RenderFillRect(sdlHandle->renderer, &rect);
        }

        SDL_RenderPresent(sdlHandle->renderer);
    }

    void PortraitRenderer::Log()
    {
        SDL_Log("%.2f - %llu | "
                "PortraitRenderer > Portrait Count(%d)",
                Time::time, Time::stepCount,
                _portraits.size());
    }
}