#include "portrait-renderer.hpp"

#include <SDL.h>
#include <algorithm>

namespace mia 
{
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
            SDL_Rect rect;
            rect.x = portrait->position->x + portrait->offset.x;
            rect.y = portrait->position->y + portrait->offset.y;
            rect.w = portrait->size.x;
            rect.h = portrait->size.y;


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
}