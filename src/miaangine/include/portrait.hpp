#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include "component.hpp"

#include "sprite.hpp"

namespace mia
{
    class Portrait : public Component
    {
    public:
        Portrait(Sprite* sprite, mia::v2f offset = mia::v2f::zero(), SDL_Color color = {255, 255, 255, 255}, mia::v2f pivot = mia::v2f::zero());
        virtual ~Portrait();

    private:
        Sprite *_sprite;
        mia::v2f _offset;
        SDL_Color _color;
        mia::v2f _pivot;

    public:
        const Sprite* sprite() const;
        mia::v2f offset() const;
        SDL_Color color() const;
        mia::v2f pivot() const;
        rect getRect() const;

        Sprite* sprite();
        mia::v2f& offset();
        SDL_Color& color();
        mia::v2f& pivot();

    public:
        int getID() const override;
        const char* ToStr() const override;
        bool Init() override;
        // bool SetActive(bool newState) override;
    };
}

#endif