#include "miaangine.hpp"

#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif

int main(int argc, char *argv[])
{
    mia::Init();

    

    while (true)
    {
        mia::RegisterInput();

        if (mia::inputManager->IsQuit()) break;
        
        mia::NextFrame();
    }

    mia::End();

    return 0;
}