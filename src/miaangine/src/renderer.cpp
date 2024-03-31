#include "renderer.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Renderer::Renderer()
    {}

    Renderer::~Renderer()
    {}
#pragma endregion

#pragma region Public method
    void Renderer::RegisterPortrait(Portrait *portrait)
    {
        _portraits.push_back(portrait);
    }

    void Renderer::RemovePortrait(Portrait *portrait)
    {
        auto listenerIterator = std::find(_portraits.begin(), _portraits.end(), portrait);

        if (listenerIterator != _portraits.end())
        {
            _portraits.erase(listenerIterator);
        }
    }

    void Renderer::Render(SDL_Renderer *renderer)
    {
        RenderPortraits(renderer);
    }
#pragma endregion

#pragma region Private method
    void Renderer::RenderPortraits(SDL_Renderer *renderer)
    {
        for (Portrait *portrait : _portraits)
        {
            SDL_Texture *texture = portrait->sprite()->texture;

            int w = 0, h = 0;
            if (SDL_QueryTexture(texture, NULL, NULL, &w, &h) != 0)
            {
                // TODO Add Error
                continue;
            }

            mia::v2f position = portrait->master()->GetScreenPosition() + (portrait->offset() * PPU);

            SDL_Rect rect; // TODO Add more scaling base on camera
            rect.w = w;
            rect.h = h;
            rect.x = position.x - w * portrait->pivot().x;
            rect.y = position.y - h * portrait->pivot().y;
        
            SDL_SetTextureColorMod(texture, portrait->color().r, portrait->color().b, portrait->color().g);
            SDL_SetTextureAlphaMod(texture, portrait->color().a);

            SDL_RenderCopy(renderer, texture, NULL, &rect);
        }
    }
#pragma endregion
}