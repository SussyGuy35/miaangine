#ifndef _MIA_CLIP_HPP
#define _MIA_CLIP_HPP

#include "common.hpp"

#include "sprite.hpp"

namespace mia
{
    class Clip
    {
    public:
        Clip(int initIndex = 0);
        virtual ~Clip();

        std::vector<Sprite*> _spriteList;
        int _index;

        void AddSprite(Sprite *sprite);
        Sprite* GetCurrentSprite();
        Sprite* NextSprite();
        void SetIndex(int index);

        void DestroyAllSprite();

        int MakeAnimation(const char *source, v2i position, v2i size, v2i sizePerCut);
    };
}

#endif