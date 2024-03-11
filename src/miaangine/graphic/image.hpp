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
        Image(vector2 size = vector2::zero(), vector2 offset = vector2::zero(), SDL_Color color = {255, 255, 255, 255});
        Image(float sx, float sy, float ox = 0, float oy = 0, SDL_Color color = {255, 255, 255, 255});

        virtual ~Image();

    private:
        std::string _unclaimName;
        vector2 _unclaimPosition;

    public:
        vector2 size;
        vector2 offset;

        std::string *name = &_unclaimName;
        vector2 *position = &_unclaimPosition;

        SDL_Color color;

        ScreenObject *master;

        void ShiftMaster(ScreenObject *master);
    };  
// }

#endif