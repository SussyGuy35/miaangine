#include "game.hpp"
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    srand(std::time(0));

    Game *game = new Game();

    game->Run();

    return 0;
}