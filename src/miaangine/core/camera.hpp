#ifndef _MIA_CAMERA_HPP
#define _MIA_CAMERA_HPP

#include "util/math.hpp"

namespace mia
{
    class Camera
    {
    private:
        static Camera *__instance;
    public:
        static Camera* Instance() 
        {
            if (!__instance) __instance = new Camera(); 
            return __instance;
        }

        Camera(const Camera&) = delete;
        void operator=(const Camera&) = delete;

    private:
        Camera();
    
    public:
        ~Camera();
 
    public:
        Vector2 position;
    };
}

#endif