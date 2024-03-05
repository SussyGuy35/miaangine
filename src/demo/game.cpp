#include "game.hpp"

#include <memory>

#include "bird.hpp"
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
    Bird *box = new Bird(100, 250);
}