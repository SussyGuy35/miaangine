#include "miaangine.hpp"

#include "game-manager.hpp"

int main(int argc, char* argv[])
{
    std::srand(std::time(0));

    mia::_Game().InitWindow();

    Player *player = new Player(0.0, 0.0);

    GameManager::Instance().Init(player);
    GameManager::Instance().MakeLevel("./../asset/level00.txt");
    GameManager::Instance().LoadMainMenu();

    while (true)
    {
        if (mia::_Input().getKeyDown(SDL_SCANCODE_R)) GameManager::Instance().ReloadLevel();

        mia::_Game().Update();

        // printf("%f %f\n", player->position().x, player->position().y);

        if (mia::_Input().isQuit()) break;

        mia::_Game().Render();

        // SDL_Delay(50);
    }

    mia::_Game().ClearWindow();

    return 0;
}