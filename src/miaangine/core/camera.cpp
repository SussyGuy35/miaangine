#include "camera.hpp"

namespace mia
{
    #pragma region Constructor_Destructor
    Camera::Camera():
        _size(10),
        _position(Vector2<>::zero())
    {}

    Camera::~Camera()
    {}
    #pragma endregion

    #pragma region Attributes accessing
    const float& Camera::size() const
    {
        return _size;
    }
    const Vector2<>& Camera::position() const
    {
        return _position;
    }

    float& Camera::size()
    {
        return _size;
    }
    Vector2<>& Camera::position()
    {
        return _position;
    }
    #pragma endregion
}
