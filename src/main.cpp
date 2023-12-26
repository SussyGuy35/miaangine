#include <core/engine.hpp>
#include <input/input-manager.hpp>

#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif

#include <iostream>

int main(int argc, char* argv[])
{
    mia::Engine* engine = new mia::Engine();

    engine->Init();

    mia::Input::SetupKeyBind();

    while (true)
    {
        mia::Input::RegisterInput();

        if (mia::Input::IsQuit()) break;
        if (engine->GetGameState() == 2) break;
    }

    engine->Exit();

    return 0;
}