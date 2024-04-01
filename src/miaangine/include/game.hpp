#ifndef _MIA_GAME_HPP
#define _MIA_GAME_HPP

#include "common.hpp"

namespace mia
{
    class Game : public Singleton<Game>
    {
    private:
        friend class Singleton<Game>;
        Game();
        ~Game();

    private:
        int _windowWidth;
        int _windowHeight;

    public:
        SDL_Window *window;
        SDL_Renderer *renderer;

    public:
        int getWindowWidth() const;
        int getWindowHeight() const;

        int InitWindow();
        int ClearWindow();

        int Update();
    };
}

#endif