#include "game.hpp"

#include "block.hpp"

#include <math.h>

void Game::Run()
{
    mia::Init(800, 800, 0);

    int num = 30000;
    for (int i = 0; i < num; i++)
    {
        new Block(rand() % 600, rand() % 600, rand() % 200 + 100, (float)(rand()) / (float)(RAND_MAX) * 6.283184, rand() % 50);
    }

    // float DELAY = 0.01;
    // float lastSpawn = 0;
    // int cnt = 0;

    while (true)
    {
        mia::NewFrame();

        if (mia::input->IsQuit()) break;

        mia::debug->Log("%f", mia::time->FPS);
        mia::vector2 dir = mia::vector2::one();
        mia::Camera::Instance()->position = dir.Normalize() * (std::sin(mia::time->time * 2) * 141.421356 - 141.421356);
        // if (mia::time->time > lastSpawn + DELAY)
        // {
        //     new Block(rand() % 600, rand() % 600, rand() % 200 + 100, (float)(rand()) / (float)(RAND_MAX) * 6.283184, rand() % 50);

        //     lastSpawn = mia::time->time;
        //     cnt++;
        // }
        // mia::debug->Log("%f >>>>>> %d", mia::time->FPS, cnt);

        mia::Render();
    }

    mia::End();
}