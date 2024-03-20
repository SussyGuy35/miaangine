#include "miaangine.hpp"

#include "box.hpp"

#include <cstdlib>
#include <ctime>

#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif

int main(int argc, char *argv[])
{
    srand(std::time(0));

    mia::generic.Init(400, 600, 0);

    while (true)
    {
        mia::generic.NewFrame();

        if (mia::input.GetButtonDown("Jump"))
        {
            Box *box = new Box(rand() % static_cast<int>(mia::camera.size()), rand() % 2 + 5);
        }

        if (mia::input.IsQuit()) break;

        mia::generic.Render();
    }

    mia::generic.End();

    return 0;
}