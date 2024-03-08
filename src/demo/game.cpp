#include "game.hpp"

#include <memory>

#include "bird.hpp"
#include "pipe.hpp"
#include "pipe-manager.hpp"

void Game::Run()
{
    mia::Init(400, 600, 0);

    Bird *bird = new Bird();
    PipeManager *pipeManager = new PipeManager();

    pipeManager->Start();
    
    while (true)
    {
        mia::NewFrame();

        if (mia::Input::IsQuit()) break;

        if (bird->body()->colliding) pipeManager->Stop();

        mia::Render();
    }

    mia::End();
}