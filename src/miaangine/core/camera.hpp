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
 
    private:
        float _size;

        vector2 _position;

    public:
        float& size();

        vector2& position();

        const float& size() const;
    };
}

#endif