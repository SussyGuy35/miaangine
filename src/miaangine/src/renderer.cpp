#include "renderer.hpp"

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
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        RenderPortraits(renderer);

        SDL_RenderPresent(renderer);
    }
#pragma endregion

#pragma region Private method
    void Renderer::RenderPortraits(SDL_Renderer *renderer)
    {
        for (Portrait *portrait : _portraits)
        {
            Sprite *sprite = portrait->sprite();
            SDL_Texture *texture = sprite->texture;

            int w = 0, h = 0;
            if (SDL_QueryTexture(texture, NULL, NULL, &w, &h) != 0)
            {
                // TODO Add Error
                continue;
            }
        
            SDL_SetTextureColorMod(texture, portrait->color().r, portrait->color().b, portrait->color().g);
            SDL_SetTextureAlphaMod(texture, portrait->color().a);

            SDL_Rect dstrect = PortraitRectCalculate(*portrait);
            SDL_Rect srcrect = { sprite->position.x, sprite->position.y, sprite->size.x, sprite->size.y };

            SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
        }
    }

    SDL_Rect Renderer::PortraitRectCalculate(Portrait &portrait)
    {
        SDL_Rect rect;

        Sprite *sprite = portrait.sprite();
        float displayUnitScaler = 1.0 * Camera::Instance().unitSize() / PPU; 

        float displayW = sprite->size.x * displayUnitScaler;
        float displayH = sprite->size.y * displayUnitScaler;
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