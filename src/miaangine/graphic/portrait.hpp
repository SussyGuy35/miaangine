#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include "util/math.hpp"
#include "core/time.hpp"

#include "object/world-object.hpp"

// namespace mia 
// {
    class mia::Portrait
    {
    public:
        Portrait(Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero(), SDL_Color color = {255, 255, 255, 255});
        Portrait(float sx, float sy, float ox = 0, float oy = 0, SDL_Color color = {255, 255, 255, 255});

        ~Portrait();

    private:
        Vector2 _unclaimPosition;

    public:
        Vector2 size;
        Vector2 offset;
        Vector2 *position = &_unclaimPosition;

        SDL_Color color;

        WorldObject *master;

        virtual void Log();
    };
// }

#endif