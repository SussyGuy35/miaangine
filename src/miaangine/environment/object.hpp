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
        Object(Vector2 _position = Vector2::zero(), Portrait _portrait = Portrait());
        Object(float _x, float _y);
        ~Object();

    private:
        Vector2 m_position;
        Portrait m_portrait;

    public:
        const Vector2& position = m_position;
        const Portrait& portrait = m_portrait;

        void OnCreate();

        void Start();
        void Update();
    };
// }

#endif