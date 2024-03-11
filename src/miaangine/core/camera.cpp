#include "camera.hpp"

namespace mia
{
    Camera *Camera::__instance = nullptr;


    Camera::Camera():
        position(Vector2::zero())
    {}
}
