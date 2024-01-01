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

    engine->loop->Start();

    while (true)
    {
        mia::Input::RegisterInput();

        engine->loop->Update();

        if (mia::Input::IsQuit()) break;
        if (engine->state->GetState() == 2) break;
    }

    engine->Exit();

    return 0;
}