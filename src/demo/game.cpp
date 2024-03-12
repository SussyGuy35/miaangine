#include "game.hpp"

#include "bird.hpp"
#include "pipe.hpp"
#include "pipe-manager.hpp"
#include "UI.hpp"

void Game::Run()
{
    mia::Init(400, 600, 0);

    SImage *sImage = new SImage();

    PipeManager *pipeManager = new PipeManager();
    Bird *bird = new Bird();

    pipeManager->Start();

    mia::string c("ABCD");
    SDL_Log("%d", sizeof(c));

    while (true)
    {
        mia::NewFrame();

        if (mia::input->IsQuit()) break;

        mia::Render();
    }

    mia::End();
}