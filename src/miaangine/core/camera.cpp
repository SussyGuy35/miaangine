#include "camera.hpp"

namespace mia
{
    Camera::Camera():
        _size(6),
        _position(Vector2::zero())
    {}

    Camera::~Camera()
    {}

    float& Camera::size()
    {
        return _size;
    }
    Vector2& Camera::position()
    {
        return _position;
    }

    const float& Camera::size() const
    {
        return _size;
    }
    const Vector2& Camera::position() const
    {
        return _position;
    }
}
