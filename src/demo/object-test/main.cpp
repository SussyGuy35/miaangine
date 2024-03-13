#include "game.hpp"
#include <cstdlib>
#include <ctime>

#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif

int main(int argc, char *argv[])
{
    srand(std::time(0));

    Game *game = new Game();

    game->Run();

    return 0;
}