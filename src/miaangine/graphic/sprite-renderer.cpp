#include "sprite-renderer.hpp"

#include <algorithm>

#include "core/engine-components.hpp"
#include "miaangine-global-constant.hpp"

namespace mia 
{
    #pragma region Constructor_Destructor
    PortraitRenderer::PortraitRenderer()
    {}

    PortraitRenderer::~PortraitRenderer()
    {}
    #pragma endregion

    #pragma region Registration methods
    void PortraitRenderer::RegisterPortrait(Sprite *sprite)
    {
        _sprites.push_back(sprite);
    }

    void PortraitRenderer::RemovePortrait(Sprite *sprite)
    {
        auto listenerIterator = std::find(_sprites.begin(), _sprites.end(), sprite);

        if (listenerIterator != _sprites.end())
        {
            _sprites.erase(listenerIterator);
        }
    }
    #pragma endregion

    #pragma region Update methods
    void PortraitRenderer::Render(SDL_Renderer *renderer)
    {
        for (Sprite *sprite : _sprites)
        {
            if (sprite->hasTexture())
            {
                SDL_Rect rect = RectRenderingCalculate(sprite, PIXEL_PER_UNIT, PIXEL_PER_UNIT);

                SDL_SetRenderDrawColor(renderer, sprite->color().r, sprite->color().b, sprite->color().g, sprite->color().a);
                SDL_RenderFillRect(renderer, &rect);

                continue;
            }

            SDL_Texture *texture = sprite->texture();
            int w = 0, h = 0;
            if (SDL_QueryTexture(texture, NULL, NULL, &w, &h) != 0) 
            {
                // debug().Error("[PortraitRender] Failed to load texture {%s} of [Sprite(%s)]; Ignore. ", sprite->textureDirectory().str(), sprite->name().str());
                continue;
            }

            SDL_SetTextureColorMod(texture, sprite->color().r, sprite->color().b, sprite->color().g);
            SDL_SetTextureAlphaMod(texture, sprite->color().a);
            
            SDL_Rect rect = RectRenderingCalculate(sprite, w, h);

            SDL_RenderCopy(renderer, texture, NULL, &rect);
        }
    }
    #pragma endregion

    #pragma region Internal methods
    SDL_Rect PortraitRenderer::RectRenderingCalculate(Sprite *sprite, int w, int h)
    {
        SDL_Rect rect;

        float unitSize = (generic().windowWidth / camera().size());

        float displayW = 1.0 * w * sprite->scale().x * unitSize / PIXEL_PER_UNIT;
        float displayH = 1.0 * h * sprite->scale().y * unitSize / PIXEL_PER_UNIT;
        float displayX = (sprite->master().position().x + sprite->offset().x - camera().position().x) * unitSize;
        float displayY = generic().windowHeight - displayH - (sprite->master().position().y + sprite->offset().y - camera().position().y) * unitSize;

        rect.x = static_cast<int>(displayX);
        rect.y = static_cast<int>(displayY); 
        rect.w = static_cast<int>(displayW);
        rect.h = static_cast<int>(displayH);

        return rect;
    }
    #pragma endregion
}