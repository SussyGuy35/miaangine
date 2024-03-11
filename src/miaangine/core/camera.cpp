#include "camera.hpp"

namespace mia
{
    Camera *Camera::__instance = nullptr;


    Camera::Camera():
        position(vector2::zero())
    {}
}
