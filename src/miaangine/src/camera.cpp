#include "camera.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Camera::Camera():
        _size(INIT_CAMERA_SIZE),
        _position(mia::v2f::zero())
    {}

    Camera::~Camera()
    {}
#pragma endregion

#pragma region GetSet method
    float Camera::size() const
    {
        return _size;
    }
    mia::v2f Camera::position() const
    {
        return _position;
    }

    float& Camera::size()
    {
        return _size;
    }
    mia::v2f& Camera::position()
    {
        return _position;
    }
#pragma endregion

#pragma region Public method
    mia::v2f Camera::WorldToScreenPoint(mia::v2f point)
    {
        mia::v2f result = point - _position;
        result.y *= -1;
        return result;
    }
    mia::v2f Camera::ScreenToWorldPoint(mia::v2f point)
    {
        point.y *= -1;
        mia::v2f result = _position + point;
        return result;
    }
#pragma endregion
}