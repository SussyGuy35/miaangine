#include "miaangine.hpp"

#include <cstdlib>
#include <ctime>

#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif

int main(int argc, char *argv[])
{
    srand(std::time(0));

    mia::generic().Init(400, 600, 0);

    return 0;
}