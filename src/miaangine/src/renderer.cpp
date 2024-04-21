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

    void Renderer::RegisterImage(Image *image)
    {
        _imagesList.push_back(image);
    }
    void Renderer::UnregisterImage(Image *image)
    {
        auto imageIterator = std::find(_imagesList.begin(), _imagesList.end(), image);

        if (imageIterator != _imagesList.end())
        {
            _imagesList.erase(imageIterator);
        }
    }

    void Renderer::RegisterTilemap(Tilemap *tilemap)
    {
        _tilemapsList.push_back(tilemap);
    }
    void Renderer::UnregisterTilemap(Tilemap *tilemap)
    {
        auto tilemapIterator = std::find(_tilemapsList.begin(), _tilemapsList.end(), tilemap);

        if (tilemapIterator != _tilemapsList.end())
        {
            _tilemapsList.erase(tilemapIterator);
        }
    }

    void Renderer::Render(SDL_Renderer *renderer)
    {
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_RenderClear(renderer);

        RenderTilemaps(renderer);

        RenderPortraits(renderer);

        if (_renderBodies) RenderBodyRects(renderer);

        RenderImages(renderer);

        SDL_RenderPresent(renderer);
    }

    const std::vector<Portrait*> Renderer::GetPortraitList()
    {
        return _portraitsList;
    }

    void Renderer::RenderBodiesCollision(bool state)
    {
        _renderBodies = state;
    }
#pragma endregion

#pragma region Private method
    void Renderer::RenderPortraits(SDL_Renderer *renderer)
    {
        for (Portrait *portrait : _portraitsList)
        {
            const Sprite &sprite = portrait->sprite();
            SDL_Texture *texture = sprite.tex;

            if (SDL_QueryTexture(texture, NULL, NULL, NULL, NULL) != 0)
            {
                // TODO Add Error
                continue;
            }

            SDL_SetTextureColorMod(texture, portrait->color().r, portrait->color().b, portrait->color().g);
            SDL_SetTextureAlphaMod(texture, portrait->color().a);

            SDL_Rect dstrect = WorldRectToSDLScreenRect(portrait->GetRect());
            SDL_Rect srcrect = { sprite.pos.x, sprite.pos.y, sprite.siz.x, sprite.siz.y };

            SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
        }
    }
    void Renderer::RenderImages(SDL_Renderer *renderer)
    {
        for (Image *image : _imagesList)
        {
            const Sprite &sprite = image->sprite();
            SDL_Texture *texture = sprite.tex;

            if (SDL_QueryTexture(texture, NULL, NULL, NULL, NULL) != 0)
            {
                // TODO Add Error
                continue;
            }

            SDL_SetTextureColorMod(texture, image->color().r, image->color().b, image->color().g);
            SDL_SetTextureAlphaMod(texture, image->color().a);

            rect imgRect = image->GetRect();
            SDL_Rect dstrect = { (int)imgRect.pos.x, (int)imgRect.pos.y, (int)imgRect.siz.x, (int)imgRect.siz.y };
            SDL_Rect srcrect = { sprite.pos.x, sprite.pos.y, sprite.siz.x, sprite.siz.y };
        
            SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
        }
    }
    void Renderer::RenderTilemaps(SDL_Renderer *renderer)
    {
        for (Tilemap *tilemap : _tilemapsList)
        {
            for (int i = 0; i < tilemap->width(); i++)
            {
                for (int j = 0; j < tilemap->height(); j++)
                {
                    if (!tilemap->HasTile(i, j)) continue;

                    const Sprite &sprite = tilemap->GetSprite(i, j);
                    SDL_Texture *texture = sprite.tex;

                    if (SDL_QueryTexture(texture, NULL, NULL, NULL, NULL) != 0)
                    {
                        // TODO Add Error
                        continue;
                    }

                    SDL_Rect dstrect = WorldRectToSDLScreenRect(tilemap->GetSpriteRect(i, j));
                    SDL_Rect srcrect = { sprite.pos.x, sprite.pos.y, sprite.siz.x, sprite.siz.y };

                    SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
                }
            }
        }
    }
    void Renderer::RenderBodyRects(SDL_Renderer *renderer)
    {
        const std::vector<Body*> bodyList = Physics::Instance().GetBodiesList();
        for (Body *body : bodyList)
        {
            SDL_Rect rect = WorldRectToSDLScreenRect(body->GetRect());;

            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderDrawRect(renderer, &rect);
        }
    }

    SDL_Rect Renderer::WorldRectToSDLScreenRect(const rect& worldRect)
    {
        SDL_Rect screenRect;
        v2f topleft = Camera::Instance().WorldToScreenPoint(worldRect.pos + v2f::up() * worldRect.siz.y);
        screenRect.w = static_cast<int>(worldRect.siz.x * Camera::Instance().unitSize());
        screenRect.h = static_cast<int>(worldRect.siz.y * Camera::Instance().unitSize());
        screenRect.x = static_cast<int>(topleft.x);
        screenRect.y = static_cast<int>(topleft.y);

        return screenRect;
    }
#pragma endregion
}