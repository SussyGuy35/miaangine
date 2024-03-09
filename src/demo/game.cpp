#include "game.hpp"

#include <memory>

#include "bird.hpp"
#include "pipe.hpp"
#include "pipe-manager.hpp"

void Game::Run()
{
    mia::Init(400, 600, 0);

    PipeManager *pipeManager = new PipeManager();
    Bird *bird = new Bird();

    pipeManager->Start();
    mia::debug->Log("d %^o d", bird);

    while (true)
    {
        mia::NewFrame();

        if (mia::input->IsQuit()) break;

        mia::Render();
    }

    mia::End();
}