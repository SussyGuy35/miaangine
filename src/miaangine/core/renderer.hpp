#ifndef _MIA_RENDERER_HPP
#define _MIA_RENDERER_HPP

#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/glu.h>

namespace mia 
{
    class Renderer
    {
    public:
        Renderer();
        ~Renderer();

    public:
        bool Render(SDL_Renderer* _renderer);
    };
}

#endif