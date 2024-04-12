#include "sprite-handler.hpp"

namespace mia
{
#pragma region Constructor
    SpriteHandler::SpriteHandler()
    {}

    SpriteHandler::~SpriteHandler()
    {
        SDL_DestroyTexture(_texture);
        DestroyAllCuts();
        _sprites.clear();
    }
#pragma endregion

#pragma region GetSet method
    const char* SpriteHandler::getSource() const
    {
        return _source;
    }
    const SDL_Texture* SpriteHandler::getTexture() const
    {
        return _texture;
    }
#pragma endregion

#pragma region Public method
    void SpriteHandler::SetSource(const char *source)
    {
        
        SDL_DestroyTexture(_texture);
        _texture = IMG_LoadTexture(Game::Instance().renderer, source);

        if (SDL_QueryTexture(_texture, NULL, NULL, NULL, NULL) != 0)
        {
            // TODO safety
            return;
        }
        
        for (Sprite *sprite : _sprites) 
        {
            sprite->tex = _texture;
        }
    }

    Sprite* SpriteHandler::MakeCut(v2i position, v2i size)
    {
        Sprite *sprite = new Sprite(_texture, position, size);
        _sprites.push_back(sprite);

        return sprite;
    }

    void SpriteHandler::DestroyCut(Sprite *sprite)
    {
        auto spriteIterator = std::find(_sprites.begin(), _sprites.end(), sprite);

        if (spriteIterator != _sprites.end())
        {
            _sprites.erase(spriteIterator);
        }
    }

    void SpriteHandler::DestroyAllCuts()
    {
        for (Sprite *sprite : _sprites) delete sprite;
        _sprites.clear();
    }
#pragma endregion
}