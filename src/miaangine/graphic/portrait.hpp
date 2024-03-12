#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include <SDL.h>
#include <memory>

#include "util/math.hpp"

#include "object/world-object.hpp"

// namespace mia 
// {
    class mia::Portrait
    {
    public:
        Portrait(vector2 size = vector2::zero(), vector2 offset = vector2::zero(), SDL_Color color = {255, 255, 255, 255});
        Portrait(float sx, float sy, float ox = 0, float oy = 0, SDL_Color color = {255, 255, 255, 255});

        virtual ~Portrait();

    private:
        string _unclaimName;
        vector2 _unclaimPosition;

    public:
        vector2 size;
        vector2 offset;

        string *name = &_unclaimName;
        vector2 *position = &_unclaimPosition;

        SDL_Color color;

        WorldObject *master;

        void ShiftMaster(WorldObject *master);
    };
// }

#endif