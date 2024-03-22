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

    while (true)
    {
        generic().NewFrame();

        if (input().isQuit()) break;
    }

    generic().End();

    return 0;
}