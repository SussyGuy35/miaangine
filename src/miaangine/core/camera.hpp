#ifndef _MIA_CAMERA_HPP
#define _MIA_CAMERA_HPP

#include "util/math.hpp"
#include "util/singleton.hpp"

namespace mia
{
    class Camera : public Singleton<Camera>
    {
    private:
        friend class Singleton<Camera>;
        Camera();
        ~Camera();
 
    public:
        vector2 position;
    };
}

#endif