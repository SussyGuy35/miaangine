#include "miaangine.hpp"
#include <string>

int main(int argc, char* argv[])
{
    mia::_Game().InitWindow();

    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/Character.png");

    mia::WorldObject *obj = new mia::WorldObject();
    obj->AddComponent(new mia::Portrait(
        mia::_SpriteHandler().MakeCut(mia::v2i(0, 0), mia::v2i(32, 32))
    ));

    while (true)
    {
        mia::_Game().Update();

        printf("%f %f\n", mia::_Camera().ScreenToWorldPoint(mia::_Input().getMousePosition()).x, mia::_Camera().ScreenToWorldPoint(mia::_Input().getMousePosition()).y);

        if (mia::_Input().isQuit()) break;
    }

    mia::_Game().ClearWindow();

    return 0;
}