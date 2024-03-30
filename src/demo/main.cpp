#include "miaangine.hpp"
#include <string>

int main(int argc, char* argv[])
{
    mia::Game::Instance().InitWindow();

    SDL_Delay(1000);

    return 0;
}