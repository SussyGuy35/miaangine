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
    Box* box = new Box();
    mia::eventManager->onEnterNewFrame->RegisterListener(box);
    mia::portraitRenderer->RegisterPortrait(box);
}