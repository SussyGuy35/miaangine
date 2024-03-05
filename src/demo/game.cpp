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
    Box *boxtwo = new Box(500, 10);
    Pipe *pipe = new Pipe(100, 500);

    box->fall = true;
}