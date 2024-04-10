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
        auto portraitIterator = std::find(_portraitsList.begin(), _portraitsList.end(), portrait);

        if (portraitIterator != _portraitsList.end())
        {
            _portraitsList.erase(portraitIterator);
        }
    }

    const std::vector<Portrait*> Renderer::GetPortraitssList()
    {
        return _portraitsList;
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

            if (SDL_QueryTexture(texture, NULL, NULL, NULL, NULL) != 0)
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
        SDL_Rect screenRect;
        rect worldRect = portrait.GetRect();

        v2f topleft = Camera::Instance().WorldToScreenPoint(worldRect.pos + v2f::up() * worldRect.siz.y);
        screenRect.w = static_cast<int>(worldRect.siz.x * Camera::Instance().unitSize());
        screenRect.h = static_cast<int>(worldRect.siz.y * Camera::Instance().unitSize());
        screenRect.x = static_cast<int>(topleft.x);
        screenRect.y = static_cast<int>(topleft.y);

        return screenRect;
    }
#pragma endregion
}