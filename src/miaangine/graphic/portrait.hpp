#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include <SDL.h>
#include "util/mia-math.hpp"

namespace mia
{
    class Portrait
    {
    public:
        Portrait();
        ~Portrait();

    private:
        Vector2 m_offset;
        Vector2 m_size;
        SDL_Color m_color;
    };
}

#endif