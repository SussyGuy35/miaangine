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
        return 1.0 * _size * _screenHeight / _screenWidth;
    }
    float Camera::size() const
    {
        return _size;
    }
    v2f Camera::position() const
    {
        return _position;
    }
    float Camera::unitSize() const
    {
        return 1.0 * _screenWidth / _size;
    }
    quadtree::Box<float> Camera::getRect() const
    {
        quadtree::Box<float> res;
        res.width = getCameraWidth();
        res.height = getCameraHeight();
        res.left = _position.x;
        res.top = _position.y;
        return res;
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

    float Camera::Resize(float newSize, v2f pivot)
    {
        v2f delta = v2f(
            pivot.x * getCameraWidth() * (1 - newSize / _size),
            pivot.y * getCameraHeight() * (1 - newSize / _size)
        );

        _position += delta;
        _size = newSize;
    }

    v2f Camera::WorldToScreenPoint(v2f point)
    {
        v2f res = v2f();
        res.x = point.x - _position.x;
        res.y = _position.y + getCameraHeight() - point.y;
        res *= unitSize();

        return res;
    }
    v2f Camera::ScreenToWorldPoint(v2f point)
    {
        v2f res = v2f();
        point /= 1.0 * unitSize();
        res.x = _position.x + point.x;
        res.y = _position.y + getCameraHeight() - point.y;
        
        return res;
    }
#pragma endregion
}