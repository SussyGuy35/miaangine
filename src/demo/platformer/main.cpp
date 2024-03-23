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

    generic().Init(960, 540, 0);

    Object *box = new Object("Box", 1, 1);
    box->InitSprite(1, 1);

    while (true)
    {
        generic().NewFrame();

        if (input().isQuit()) break;

        generic().Render();
    }

    generic().End();

    return 0;
}