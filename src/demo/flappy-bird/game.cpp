#include "game.hpp"

#include "bird.hpp"
#include "pipe.hpp"
#include "pipe-manager.hpp"
#include "UI.hpp"

void Game::Run()
{
    mia::generic.Init(400, 600, 0);
    mia::sdl.SetAssetDir("D:/SDL/miaangine/asset/flappy-bird");
    
    SImage *sImage = new SImage();

    PipeManager *pipeManager = new PipeManager();
    Bird *bird = new Bird();
    
    pipeManager->Start();

    while (true)
    {
        mia::generic.NewFrame();

        if (mia::input.IsQuit()) break;

        mia::generic.Render();
    }

    mia::generic.End();
}