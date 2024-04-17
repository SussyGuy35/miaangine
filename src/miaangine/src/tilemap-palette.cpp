#include "tilemap-palette.hpp"

namespace mia
{
    TilemapPalette::TilemapPalette():
        _sprites(std::vector<Sprite*>())
    {}

    TilemapPalette::~TilemapPalette()
    {}

    Sprite* TilemapPalette::AddSprite(Sprite *sprite)
    {
        _sprites.push_back(sprite);
    }
    void TilemapPalette::RemoveSprite(Sprite *sprite)
    {
        auto spriteIterator = std::find(_sprites.begin(), _sprites.end(), sprite);

        if (spriteIterator != _sprites.end())
        {
            _sprites.erase(spriteIterator);
        }
    }

    Sprite* TilemapPalette::GetSprite(int index)
    {
        if (index >= _sprites.size() || !_sprites[index])
        {
            // TODO error
        }

        return _sprites[index];
    }
    SDL_Texture* TilemapPalette::GetTexture(int index)
    {
        if (index >= _sprites.size())
        {
            // TODO error
        }

        if (SDL_QueryTexture(_sprites[index]->tex, NULL, NULL, NULL, NULL) != 0)
        {
            // TODO error
        }

        return _sprites[index]->tex;
    }
}