#include "game.hpp"

#include <memory>

#include "box.hpp"
#include "pipe.hpp"

void Game::Run()
{
    mia::Init();

    InitScene();
    
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
    mia::events->mainFrameStepLoop->RegisterListener(box);
    box->MakePortrait(50, 50);
    mia::portraitRenderer->RegisterPortrait(box->portrait);
    box->fall = true;

    Box *boxtwo = new Box(500, 10);
    mia::events->mainFrameStepLoop->RegisterListener(boxtwo);
    boxtwo->MakePortrait(50, 50);
    mia::portraitRenderer->RegisterPortrait(boxtwo->portrait);

    Pipe *pipe = new Pipe(300, 200);
    mia::events->mainFrameStepLoop->RegisterListener(pipe);
    pipe->MakePortrait(50, 50);
    mia::portraitRenderer->RegisterPortrait(pipe->portrait);

    mia::portraitRenderer->Log();
    
}