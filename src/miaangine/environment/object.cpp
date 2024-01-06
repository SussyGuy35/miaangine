#include "object.hpp"

namespace mia
{
    Object::Object():
        m_position(Vector2::zero()),
        m_portrait(Portrait())
    {

    }
    Object::Object(Vector2 _position):
        m_position(_position),
        m_portrait(Portrait())
    {

    }
    Object::Object(float _x, float _y):
        m_position(Vector2(_x, _y)),
        m_portrait(Portrait())
    {

    }

    Object::~Object()
    {

    }

    void Object::Start()
    {
        
    }

    void Object::Update()
    {

    }

    Portrait Object::MakeRect(Vector2 _size, SDL_Color _color, Vector2 _offset)
    {
        m_portrait.SetSize(_size);
        m_portrait.SetColor(_color);
        m_portrait.SetOffset(_offset);
        m_portrait.SetEnable(true);
        m_portrait.SetPosition(m_position);

        return m_portrait;
    }
    Portrait Object::MakeRect(float _x, float _y, SDL_Color _color, float _offsetX, float _offsetY)
    {
        m_portrait.SetSize(Vector2(_x, _y));
        m_portrait.SetColor(_color);
        m_portrait.SetOffset(Vector2(_offsetX, _offsetY));
        m_portrait.SetEnable(true);
        m_portrait.SetPosition(m_position);

        return m_portrait;
    }
}