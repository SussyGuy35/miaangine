#ifndef _MIA_IMAGE_HPP
#define _MIA_IMAGE_HPP

#include "UI.hpp"

#include "sprite.hpp"

#include "util/rect.hpp"

namespace mia
{
    class Image : public Entity
    {
    public:
        Image(UI *master, Sprite *sprite, v2f size = v2f::one(), v2f pivot = v2f::zero(), v2f offset = v2f::zero(), SDL_Color color = {255, 255, 255, 255});
        virtual ~Image();

    private:
        UI *_master;

        Sprite *_sprite;
        v2f _size;
        v2f _pivot;
        v2f _offset;
        SDL_Color _color;

    public:
        const UI& master() const;
        const Sprite& sprite() const;
        const v2f& size() const;
        const v2f& pivot() const;
        const v2f& offset() const;
        const SDL_Color& color() const;

        UI& master();
        const Sprite& setSprite(Sprite *sprite);
        v2f& size();
        v2f& pivot();
        v2f& offset();
        SDL_Color& color();

        UI& ChangeMaster(UI *newMaster);

        rect GetRect() const;

    public:
        int getID() const override;
        const char* ToStr() const override;
    };
}

#endif