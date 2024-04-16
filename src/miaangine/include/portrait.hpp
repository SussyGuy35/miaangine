#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include "object.hpp"

#include "sprite.hpp"

#include "util/rect.hpp"

namespace mia
{
    class Portrait : public Entity
    {
    public:
        Portrait(Object *master, Sprite *sprite, v2f pivot = v2f::zero(), v2f offset = v2f::zero(), SDL_Color color = {255, 255, 255, 255});
        virtual ~Portrait();

    private:
        Object *_master;
        
        Sprite *_sprite;
        v2f _offset;
        SDL_Color _color;
        v2f _pivot;

    public:
        const Object& master() const;
        const Sprite& sprite() const;
        const v2f& offset() const;
        const SDL_Color& color() const;
        const v2f& pivot() const;

        Object& master();
        v2f& offset();
        const Sprite& setSprite(Sprite *sprite);
        SDL_Color& color();
        v2f& pivot();

        Object& ChangeMaster(Object *newMaster);

        rect GetRect() const;

    public:
        int getID() const override;
        const char* ToStr() const override;
    };
}

#endif