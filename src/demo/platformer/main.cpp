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
    mia::sdl.SetAssetDir("D:/SDL/miaangine/asset/flappy-bird");

    bool spawning = true;

    while (true)
    {
        mia::generic.NewFrame();

        Box *box;
        if (spawning) 
        {
            box = new Box(
                static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (mia::camera.size() - 1))), 
                static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (10)))
            );
        }
        if (mia::input.GetButtonDown("Jump")) spawning = !spawning;

        if (mia::input.IsQuit()) break;

        mia::generic.Render();
    }

    mia::generic.End();

    return 0;
}