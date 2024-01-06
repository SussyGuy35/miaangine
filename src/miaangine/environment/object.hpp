#ifndef _MIA_OBJECT_HPP
#define _MIA_OBJECT_HPP

#include "object-forward.hpp"

#include "util/mia-math.hpp"

#include "graphic/portrait.hpp"

// namespace mia
// {
    class mia::Object 
    {
    public:
        Object();
        Object(Vector2 _position);
        Object(float _x, float _y);
        ~Object();

    private:
        Vector2 m_position;
        Portrait m_portrait;

    public:
        const Vector2& position = m_position;
        const Portrait& portrait = m_portrait;

        void Start();
        void Update();

        Portrait MakeRect(Vector2 _size, SDL_Color _color = { 0, 0, 0, 0 }, Vector2 _offset = Vector2::zero());
        Portrait MakeRect(float _x, float _y, SDL_Color _color = { 0, 0, 0, 0 }, float _offsetX = 0.0, float _offsetY = 0.0);
    };
// }

#endif