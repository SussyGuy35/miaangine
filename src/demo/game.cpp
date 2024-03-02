#include "game.hpp"

#include <memory>

#include "box.hpp"

void Game::Run()
{
    mia::Init();

    InitScene();

    mia::sdlHandle->Log();

    while (true)
    {
        mia::NewFrame();

        if (mia::inputs->IsQuit()) break;

        mia::Render();
    }

    mia::End();
}

void Game::InitScene()
{
    Box *box = new Box(100, 10);
    mia::events->mainFrameLoop->RegisterListener(box);
    box->MakePortrait(50, 50);
    mia::portraitRenderer->RegisterPortrait(box->portrait);
    box->fall = true;
}