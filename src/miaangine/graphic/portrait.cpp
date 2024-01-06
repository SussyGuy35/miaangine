#include "portrait.hpp"

namespace mia 
{
    Portrait::Portrait():
        m_enabled(false),
        m_size(Vector2::zero()),
        m_color({0, 0, 0, 0}),
        m_offset(Vector2::zero()),
        m_position(Vector2::zero())
    {

    }
    Portrait::Portrait(bool _enabled):
        m_enabled(_enabled),
        m_size(Vector2::zero()),
        m_color({0, 0, 0, 0}),
        m_offset(Vector2::zero()),
        m_position(Vector2::zero())
    {

    }

    Portrait::~Portrait()
    {

    }

    void Portrait::SetEnable(bool _state)
    {
        m_enabled = _state;
    }

    void Portrait::SetSize(Vector2 _size)
    {
        m_size = _size;
    }

    void Portrait::SetColor(SDL_Color _color)
    {
        m_color = { _color.r, _color.b, _color.g, _color.a };
    }

    void Portrait::SetOffset(Vector2 _offset)
    {
        m_offset = _offset;
    }

    void Portrait::SetPosition(Vector2 _position)
    {
        m_position = _position;
    }
}