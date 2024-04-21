#include "sprite-handler.hpp"

namespace mia
{
#pragma region Constructor
    SpriteHandler::SpriteHandler()
    {}

    SpriteHandler::~SpriteHandler()
    {
        SDL_DestroyTexture(_texture);
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
        // SDL_DestroyTexture(_texture);
        _texture = IMG_LoadTexture(Game::Instance().renderer, source);

        if (SDL_QueryTexture(_texture, NULL, NULL, NULL, NULL) != 0)
        {
            // TODO safety
            printf("Wrong source you moron\n");
            return;
        }
    }

    Sprite* SpriteHandler::MakeCut(v2i position, v2i size)
    {
        Sprite *sprite = new Sprite(_texture, position, size);

        return sprite;
    }
#pragma endregion
}