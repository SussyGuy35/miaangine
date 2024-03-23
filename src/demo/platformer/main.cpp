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

    (new Object("Box", 0, 1))->InitSprite(1, 1);
    (new Object("Box", 1, 2))->InitSprite(1, 1);
    (new Object("Box", 2, 1))->InitSprite(1, 1);
    (new Object("Box", 3, 2))->InitSprite(1, 1);
    (new Object("Box", 4, 1))->InitSprite(1, 1);
    (new Object("Box", 5, 2))->InitSprite(1, 1);
    (new Object("Box", 6, 1))->InitSprite(1, 1);
    (new Object("Box", 7, 2))->InitSprite(1, 1);
    (new Object("Box", 8, 1))->InitSprite(1, 1);
    (new Object("Box", 9, 0))->InitSprite(1, 1);

    while (true)
    {
        generic().NewFrame();

        if (input().isQuit()) break;

        generic().Render();
    }

    generic().End();

    return 0;
}