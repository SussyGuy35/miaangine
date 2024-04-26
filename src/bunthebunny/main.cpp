#include "miaangine.hpp"

#include "game-manager.hpp"
#include "startmenu.hpp"

int main(int argc, char* argv[])
{
    std::srand(std::time(0));

    mia::_Game().InitWindow();

    Player *player = new Player(-1000, 1000);

    GameManager::Instance().Init(player, "./../asset/score.txt");
    GameManager::Instance().MakeLevel("./../asset/level00.txt");
    GameManager::Instance().MakeLevel("./../asset/level01.txt");
    GameManager::Instance().MakeLevel("./../asset/level02.txt");

    StartM *startScreen = new StartM();

    while (true)
    {
        mia::_Game().Update();

        if (mia::_Input().isQuit()) break;

        mia::_Game().Render();
    }

    mia::_Game().ClearWindow();

    return 0;
}