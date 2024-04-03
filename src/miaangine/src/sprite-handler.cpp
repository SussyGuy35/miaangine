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
        // TODO safety
        
        SDL_DestroyTexture(_texture);
        _texture = IMG_LoadTexture(Game::Instance().renderer, source);

        for (Sprite *sprite : _sprites) 
        {
            sprite->texture = _texture;
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