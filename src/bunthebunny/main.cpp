#include "miaangine.hpp"

#include "box.hpp"
#include "player/player.hpp"

int main(int argc, char* argv[])
{
    std::srand(std::time(0));

    mia::_Game().InitWindow();

    std::vector<Box*> boxes;
    boxes.push_back( new Box(0, 0, 100, 1) );

    mia::_Renderer().RenderBodiesCollision(true);

    Player *player = new Player(5, 5);

    while (true)
    {
        mia::_Game().Update();

        if (mia::_Input().isQuit()) break;

        mia::_Game().Render();
    }

    mia::_Game().ClearWindow();

    return 0;
}