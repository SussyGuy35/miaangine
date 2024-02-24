#include "game.hpp"

#include <iostream>
#include "box.hpp"

void Game::Run()
{
    mia::Init();

    InitScene();

    while (true)
    {
        mia::NewFrame();

        if (mia::inputManager->IsQuit()) break;

        mia::Render();
    }

    mia::End();
}

void Game::InitScene()
{
    Box *box = new Box(100, 10);
    mia::eventManager->mainFrameLoop->RegisterListener(box);
    box->MakePortrait(50, 50);
    mia::portraitRenderer->RegisterPortrait(box->portrait);
}