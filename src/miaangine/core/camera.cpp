#include "camera.hpp"

#include "miaangine-global-constant.hpp"

namespace mia
{
    #pragma region Constructor_Destructor
    Camera::Camera():
        _size(CAMERA_SIZE),
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
