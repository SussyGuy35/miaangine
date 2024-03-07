#include "game.hpp"

#include <memory>

#include "bird.hpp"
#include "pipe.hpp"
#include "pipe-manager.hpp"

void Game::Run()
{
    mia::Init();

    Bird *bird = new Bird(70, 250);
    PipeManager *pipeManager = new PipeManager();

    pipeManager->Start();
    
    while (true)
    {
        mia::NewFrame();

        if (mia::inputs->IsQuit()) break;

        if (bird->body()->colliding) pipeManager->Stop();

        mia::Render();
    }

    mia::End();
}