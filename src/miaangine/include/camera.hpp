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
        mia::v2f _position;
        float _size; // Ammount of unit appear on the width of the screen

    public:
        mia::v2f position() const;
        float size() const;

        mia::v2f& position();
        float& size();
    
        mia::v2f WorldToScreenPoint(mia::v2f point);
        mia::v2f ScreenToWorldPoint(mia::v2f point);
    };
}

#endif