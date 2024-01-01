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
        Object(Vector2 _position = Vector2::zero());
        Object(float _x, float _y);
        ~Object();

    private:
        Vector2 m_position;

    public:
        const Vector2& position = m_position;

        void OnCreate();

        void Start();
        void Update();
    };
// }

#endif