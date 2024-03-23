#ifndef _MIA_GENERIC_TASKS_HPP
#define _MIA_GENERIC_TASKS_HPP

#include <SDL.h>
#include <SDL_image.h>

#include "util/singleton.hpp"

namespace mia
{
    class GenericTask : public Singleton<GenericTask>
    {
    private:
        friend class Singleton<GenericTask>;
        GenericTask();
        ~GenericTask();

    public:
        // Public attributes
        int windowWidth, windowHeight;
        bool fullscreenMode;

        SDL_Window *window;
        SDL_Renderer *renderer;

        // Public methods
        int Init();
        void End();

        void NewFrame();
        void Render();

    private:
        // SDL-related methods
        int CreateWindow(int width, int height, bool fullscreen);
        void ClearWindow();
    };
}

#endif