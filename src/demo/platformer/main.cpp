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
    // bird->sprite().Load("D:/SDL/miaangine/asset/flappy-bird/bird-00.png");
    bird->InitBody(1);
    bird->InitCollider(1, 1);

    while (true)
    {
        generic().NewFrame();

        // debug().Log("%f", time().fps());

        if (input().isQuit()) break;

        generic().Render();

        // SDL_Delay(1);
    }

    generic().End();

    return 0;
}