#include "miaangine.hpp"

#include "box.hpp"

#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif

int main(int argc, char *argv[])
{
    mia::generic.Init(400, 600, 0);

    Box *box = new Box(200, 500);

    mia::debug.Log("A");

    while (true)
    {
        mia::generic.NewFrame();

        if (mia::input.IsQuit()) break;

        mia::generic.Render();
    }

    mia::generic.End();

    return 0;
}