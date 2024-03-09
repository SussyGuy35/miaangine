#include "game.hpp"

#include <memory>

#include "bird.hpp"
#include "pipe.hpp"
#include "pipe-manager.hpp"

#include "debug/log-system.hpp"

void Game::Run()
{
    mia::Init(400, 600, 0);

    PipeManager *pipeManager = new PipeManager();
    Bird *bird = new Bird();

    pipeManager->Start();


    while (true)
    {
        mia::NewFrame();

    mia::logs->Log("abcd %^o e", bird);
        if (mia::input->IsQuit()) break;

        mia::Render();
    }

    mia::End();
}