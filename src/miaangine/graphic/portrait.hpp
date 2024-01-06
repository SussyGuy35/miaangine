#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include <SDL.h>
#include "util/mia-math.hpp"

namespace mia
{
    class Portrait
    {
    public:
        Portrait();
        Portrait(bool _enabled);
        ~Portrait();

    private:
        bool m_enabled;
        Vector2 m_size;
        SDL_Color m_color;
        Vector2 m_offset;
        Vector2 m_position;

    public:
        const bool& isEnable = m_enabled;
        const Vector2& size = m_size;
        const SDL_Color& color = m_color;
        const Vector2& offset = m_offset;
        const Vector2& position = m_position;

        void SetEnable(bool _state);
        void SetSize(Vector2 _size); 
        void SetColor(SDL_Color _color);
        void SetOffset(Vector2 _offset);
        void SetPosition(Vector2 _position);
    };
}

#endif