#include "renderer.hpp"

#include "camera.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Renderer::Renderer():
        _portraitsList(std::vector<Portrait*>())
    {}

    Renderer::~Renderer()
    {}
#pragma endregion

#pragma region Public method
    void Renderer::RegisterPortrait(Portrait *portrait)
    {
        _portraitsList.push_back(portrait);
    }
    void Renderer::UnregisterPortrait(Portrait *portrait)
    {
        auto portraitIterator = std::find(_portraitsList.begin(), _portraitsList.end(), _portraitsList);

        if (portraitIterator != _portraitsList.end())
        {
            _portraitsList.erase(portraitIterator);
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
        for (Portrait *portrait : _portraitsList)
        {
            Sprite &sprite = portrait->sprite();
            SDL_Texture *texture = sprite.tex;

            int w = 0, h = 0;
            if (SDL_QueryTexture(texture, NULL, NULL, &w, &h) != 0)
            {
                // TODO Add Error
                continue;
            }

            SDL_SetTextureColorMod(texture, portrait->color().r, portrait->color().b, portrait->color().g);
            SDL_SetTextureAlphaMod(texture, portrait->color().a);

            SDL_Rect dstrect = PortraitRectCalculate(*portrait);
            SDL_Rect srcrect = { sprite.pos.x, sprite.pos.y, sprite.siz.x, sprite.siz.y };

            SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
        }
    }

    SDL_Rect Renderer::PortraitRectCalculate(Portrait &portrait)
    {
        SDL_Rect rect;

        Sprite sprite = portrait.sprite();
        float displayUnitScaler = Camera::Instance().unitSize() / PPU; 

        float displayW = sprite.siz.x * displayUnitScaler;
        float displayH = sprite.siz.y * displayUnitScaler;
        float displayX = Camera::Instance().WorldToScreenPoint(portrait.master()->position() + portrait.offset()).x - portrait.pivot().x * displayW;
        float displayY = Camera::Instance().WorldToScreenPoint(portrait.master()->position() + portrait.offset()).y - (1 - portrait.pivot().y) * displayH;

        // printf(">>> %f %f : %f %f\n", displayX, displayY, displayW, displayH);

        rect.w = static_cast<int>(displayW);
        rect.h = static_cast<int>(displayH);
        rect.x = static_cast<int>(displayX);
        rect.y = static_cast<int>(displayY);

        return rect;
    }
#pragma endregion
}