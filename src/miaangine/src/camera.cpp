#include "camera.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Camera::Camera():
        _size(INIT_CAMERA_SIZE),
        _position(v2f::zero())
    {}

    Camera::~Camera()
    {}
#pragma endregion

#pragma region GetSet method
    int Camera::getScreenWidth() const
    {
        return _screenWidth;
    }
    int Camera::getScreenHeight() const
    {
        return _screenHeight;
    }
    float Camera::getCameraWidth() const
    {
        return _size;
    }
    float Camera::getCameraHeight() const
    {
        return _size * _screenHeight / _screenWidth;
    }
    float Camera::size() const
    {
        return _size;
    }
    v2f Camera::position() const
    {
        return _position;
    }
    int Camera::unitSize() const
    {
        return 1.0 * _screenWidth / _size;
    }

    float& Camera::size()
    {
        return _size;
    }
    v2f& Camera::position()
    {
        return _position;
    }
#pragma endregion

#pragma region Public method
    v2f Camera::SetCenter(v2f position)
    {
        v2f newPos = position - v2f(getCameraWidth(), getCameraHeight()) / 2;
        return _position = newPos;
    }

    v2f Camera::WorldToScreenPoint(v2f point)
    {
        v2f result = point - _position;
        result.y *= -1;
        return result;
    }
    v2f Camera::ScreenToWorldPoint(v2f point)
    {
        point.y *= -1;
        v2f result = _position + point;
        return result;
    }
#pragma endregion
}