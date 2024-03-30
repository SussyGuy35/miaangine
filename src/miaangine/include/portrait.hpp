#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include "component.hpp"

#include "sprite.hpp"

namespace mia
{
    class Portrait : public Component
    {
    public:
        Portrait();
        virtual ~Portrait();

    private:
        Sprite *_sprite;
        mia::v2f _offset;
        SDL_Color _color;

    public:
        const Sprite* sprite() const;
        mia::v2f offset() const;
        SDL_Color color() const;

        Sprite* sprite();
        mia::v2f& offset();
        SDL_Color& color();

    public:
        const char* ToStr() const override;
        // bool SetActive(bool newState) override;
    };
}

#endif