#include "flappy-bird.hpp"

#include <iostream>
#include "box.hpp"

void Game::Run()
{
    mia::Init();

    InitScene();

    while (true)
    {
        mia::RegisterInput();

        if (mia::inputManager->IsQuit()) break;

        mia::portraitRenderer->RenderPotraits();

        mia::NextFrame();
    }

    mia::End();
}

void Game::InitScene()
{
    Box* box = new Box();
    mia::eventManager->onEnterFrame->RegisterListener(box);
    mia::portraitRenderer->RegisterPortrait(box);
}