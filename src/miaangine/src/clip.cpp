#include "clip.hpp"

#include "game.hpp"

namespace mia
{
    Clip::Clip(int initIndex):
        _spriteList(std::vector<Sprite*>()),
        _index(initIndex)
    {}

    Clip::~Clip()
    {}

    bool Clip::IsLastFrame()
    {
        return _index == _spriteList.size() - 1;
    }
    int Clip::GetIndex()
    {
        return _index;
    }
    void Clip::AddSprite(Sprite *sprite)
    {
        _spriteList.push_back(sprite);
    }
    Sprite* Clip::GetCurrentSprite()
    {
        return _spriteList[_index];    
    }
    Sprite* Clip::NextSprite()
    {
        _index++;
        if (_index >= _spriteList.size()) _index = 0;

        return _spriteList[_index];    
    }
    void Clip::SetIndex(int index)
    {
        _index = index;
    }

    void Clip::DestroyAllSprite()
    {
        for (Sprite *sprite : _spriteList)
        {
            delete sprite;
        }
    }

    int Clip::MakeAnimation(const char *source, v2i position, v2i size, v2i sizePerCut)
    {
        SDL_Texture *_texture;

        _texture = IMG_LoadTexture(Game::Instance().renderer, source);

        if (SDL_QueryTexture(_texture, NULL, NULL, NULL, NULL) != 0)
        {
            // TODO safety
            printf("Wrong source you moron\n");
            return 0;
        }

        int cnt = 0;
        for (int j = 0; j * sizePerCut.y + sizePerCut.y - 1 < size.y; j++)
        {
            for (int i = 0; i * sizePerCut.x + sizePerCut.x - 1 < size.x; i++)
            {
                Sprite *sprite = new Sprite(_texture, v2i(i * sizePerCut.x + position.x, j * sizePerCut.y + position.y), sizePerCut);

                AddSprite(sprite);
                cnt++;
            }
        }

        // SDL_DestroyTexture(_texture);

        return cnt;
    }
}