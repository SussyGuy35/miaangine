#ifndef _MIA_CAMERA_HPP
#define _MIA_CAMERA_HPP

#include "common.hpp"

namespace mia
{
    class Camera : public Singleton<Camera>
    {
    private:
        friend class Singleton<Camera>;
        Camera();
        ~Camera();
 
    private:
        int _screenWidth;
        int _screenHeight;
        float _size; // Ammount of unit appear on the width of the screen
        v2f _position;

    public:
        int getScreenWidth() const;
        int getScreenHeight() const;
        float getCameraWidth() const;
        float getCameraHeight() const;
        float size() const;
        v2f position() const;
        int unitSize() const;

        float& size();
        v2f& position();

        v2f SetCenter(v2f position);
    
        v2f WorldToScreenPoint(v2f point);
        v2f ScreenToWorldPoint(v2f point);
    };
}

#endif