#include "renderer.hpp"

#include "camera.hpp"

#include "physics.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Renderer::Renderer():
        _portraitsList(std::vector<Portrait*>()),
        _debugRectList(std::vector<std::pair<rect, SDL_Color>>())
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

    void Renderer::DrawRect(rect rect, SDL_Color color)
    {
        _debugRectList.push_back({ rect, color });
    }
    void Renderer::ClearDrawRects()
    {
        _debugRectList.clear();
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
        if (_renderBodies) RenderBodyRects(renderer);
        RenderDebugRects(renderer);

        SDL_RenderPresent(renderer);
    }

    void Renderer::SetRenderBodies(bool state)
    {
        _renderBodies = state;
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
    void Renderer::RenderBodyRects(SDL_Renderer *renderer)
    {
        const std::vector<Body*> bodyList = Physics::Instance().GetBodiesList();
        for (Body *body : bodyList)
        {
            SDL_Rect screenRect;
            rect worldRect = body->GetRect();

            v2f topleft = Camera::Instance().WorldToScreenPoint(worldRect.pos + v2f::up() * worldRect.siz.y);
            screenRect.w = static_cast<int>(worldRect.siz.x * Camera::Instance().unitSize());
            screenRect.h = static_cast<int>(worldRect.siz.y * Camera::Instance().unitSize());
            screenRect.x = static_cast<int>(topleft.x);
            screenRect.y = static_cast<int>(topleft.y);

            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderDrawRect(renderer, &screenRect);
        }
    }
    void Renderer::RenderDebugRects(SDL_Renderer *renderer)
    {
        for (auto p : _debugRectList)
        {
            SDL_Rect screenRect;
            rect worldRect = p.first;

            v2f topleft = Camera::Instance().WorldToScreenPoint(worldRect.pos + v2f::up() * worldRect.siz.y);
            screenRect.w = static_cast<int>(worldRect.siz.x * Camera::Instance().unitSize());
            screenRect.h = static_cast<int>(worldRect.siz.y * Camera::Instance().unitSize());
            screenRect.x = static_cast<int>(topleft.x);
            screenRect.y = static_cast<int>(topleft.y);

            SDL_SetRenderDrawColor(renderer, p.second.r, p.second.g, p.second.b, p.second.a);
            SDL_RenderDrawRect(renderer, &screenRect);
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