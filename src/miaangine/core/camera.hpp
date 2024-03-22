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
        // Attributes
        Vector2<> _position;
        float _size; // Ammount of unit appear on the width of the screen

    public:
        // Attributes accessing
        const float& size() const;
        const Vector2<>& position() const;

        inline float& size();
        inline Vector2<>& position();
    };
}

#endif