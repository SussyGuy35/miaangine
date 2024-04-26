#include "miaangine.hpp"

#include "game-manager.hpp"

int main(int argc, char* argv[])
{
    std::srand(std::time(0));

    mia::_Game().InitWindow();

    mia::_Renderer().SetFont("./../asset/Retro Gaming.ttf", 40);

    Player *player = new Player(-1000, 1000);

    GameManager::Instance().Init(player, "./../asset/score.txt");
    GameManager::Instance().MakeLevel("./../asset/level00.txt");
    GameManager::Instance().LoadLevel(0);
    GameManager::Instance().LoadMainMenu();

    while (true)
    {
        if (mia::_Input().getKeyDown(SDL_SCANCODE_R)) GameManager::Instance().ReloadLevel();

        mia::_Game().Update();

        // SDL_Log("%f %f\n", player->position().x, player->position().y);

        if (mia::_Input().isQuit()) break;

        mia::_Game().Render();

        // SDL_Delay(50);
    }

    mia::_Game().ClearWindow();

    return 0;
}