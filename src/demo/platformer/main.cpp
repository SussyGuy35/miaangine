#include "miaangine.hpp"

#include <cstdlib>
#include <ctime>

#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif

using namespace mia;

int main(int argc, char *argv[])
{
    srand(std::time(0));

    generic().Init();

    Object *bird = new Object("Bird", 1, 1);
    bird->InitSprite(1, 1);
    bird->sprite().Load("D:/SDL/miaangine/asset/flappy-bird/bird-00.png");

    while (true)
    {
        generic().NewFrame();

        if (input().isQuit()) break;

        generic().Render();
    }

    generic().End();

    return 0;
}