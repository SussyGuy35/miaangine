#ifndef _MIA_CAMERA_HPP
#define _MIA_CAMERA_HPP

#include "util/math.hpp"

namespace mia
{
    class Camera
    {
    private:
        Camera();

    public:
        static const int PIXEL_PER_UNIT = 10;

        static Vector2 position;
    };
}

#endif