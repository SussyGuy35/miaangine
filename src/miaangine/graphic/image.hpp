#ifndef _MIA_IMAGE_HPP
#define _MIA_IMAGE_HPP

#include <SDL.h>

#include "util/math.hpp"

#include "object/screen-object.hpp"

// namespace mia
// {
    class mia::Image
    {
    public:
        Image(vector2 size = vector2::zero(), vector2 offset = vector2::zero());
        Image(float sx, float sy, float ox = 0, float oy = 0);

        virtual ~Image();

    private:
        string _ucName;
        vector2 _ucPosition;

        ScreenObject *_master;

    public:
        vector2 size;
        vector2 offset;

        string& name();
        vector2& position(); 

        ScreenObject* master();

        SDL_Color color;

        void ShiftMaster(ScreenObject *master);
    };  
// }

#endif