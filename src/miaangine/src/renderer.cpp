#include "renderer.hpp"

#include "game.hpp"
#include "camera.hpp"

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
        auto portraitIterator = std::find(_portraits.begin(), _portraits.end(), portrait);

        if (portraitIterator != _portraits.end())
        {
            _portraits.erase(portraitIterator);
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

            SDL_Rect rect = PortraitRectCalculate(*portrait, w, h);
        
            SDL_SetTextureColorMod(texture, portrait->color().r, portrait->color().b, portrait->color().g);
            SDL_SetTextureAlphaMod(texture, portrait->color().a);

            SDL_RenderCopy(renderer, texture, NULL, &rect);
        }
    }

    SDL_Rect Renderer::PortraitRectCalculate(Portrait &portrait, int w, int h)
    {
        SDL_Rect rect;

        float unitSize = Game::Instance().getWindowWidth() / Camera::Instance().size();
        float displayUnitScaler = unitSize / PPU; 

        float displayW = w * displayUnitScaler;
        float displayH = h * displayUnitScaler;
        float displayX = Camera::Instance().WorldToScreenPoint(portrait.master()->position() + portrait.offset()).x - portrait.pivot().x * displayW;
        float displayY = Camera::Instance().WorldToScreenPoint(portrait.master()->position() + portrait.offset()).y - portrait.pivot().y * displayH;

        rect.w = static_cast<int>(displayW);
        rect.h = static_cast<int>(displayH);
        rect.x = static_cast<int>(displayX);
        rect.y = static_cast<int>(displayY);

        return rect;
    }
#pragma endregion
}