#include "camera.hpp"

namespace mia
{
    Camera::Camera():
        _size(6),
        _position(vector2::zero())
    {}

    Camera::~Camera()
    {}

    float& Camera::size()
    {
        return _size;
    }
    vector2& Camera::position()
    {
        return _position;
    }

    const float& Camera::size() const
    {
        return _size;
    }
    const vector2& Camera::position() const
    {
        return _position;
    }
}
