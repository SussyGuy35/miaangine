#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include "component.hpp"

#include "sprite.hpp"
#include "Quadtree/Box.h"

namespace mia
{
    class Portrait : public Component
    {
    public:
        Portrait(Sprite* sprite, v2f offset = v2f::zero(), SDL_Color color = {255, 255, 255, 255}, v2f pivot = v2f::zero());
        virtual ~Portrait();

    private:
        Sprite *_sprite;
        v2f _offset;
        SDL_Color _color;
        v2f _pivot;

    public:
        const Sprite* sprite() const;
        v2f offset() const;
        SDL_Color color() const;
        v2f pivot() const;
        quadtree::Box<float> getRect() const;

        Sprite* sprite();
        v2f& offset();
        SDL_Color& color();
        v2f& pivot();

    public:
        int getID() const override;
        const char* ToStr() const override;
        bool Init() override;
        // bool SetActive(bool newState) override;
    };
}

#endif