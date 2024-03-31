#include "sprite-handler.hpp"

namespace mia
{
#pragma region Constructor
    SpriteHandler::SpriteHandler(const char *source):
        _source(source)
    {
        _texture = IMG_LoadTexture(Game::Instance().renderer, source); //TODO safety
    }
    SpriteHandler::~SpriteHandler()
    {
        SDL_DestroyTexture(_texture);
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
    void SpriteHandler::ChangeTexture(const char *newSource)
    {
        SDL_DestroyTexture(_texture);
        _texture = IMG_LoadTexture(Game::Instance().renderer, newSource);

        for (Sprite *sprite : _sprites) 
        {
            sprite->texture = _texture;
        }
    }

    void SpriteHandler::MakeCut(mia::v2i position, mia::v2i size)
    {
        Sprite *sprite = new Sprite(_texture, position, size);
        _sprites.push_back(sprite);
    }

    void SpriteHandler::DestroyCuts()
    {
        for (Sprite *sprite : _sprites) delete sprite;
        _sprites.clear();
    }
#pragma endregion
}