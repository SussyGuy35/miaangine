#include "miaangine.hpp"
#include <string>

int main(int argc, char* argv[])
{
    mia::_Game().InitWindow();

    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/SpriteTest.png");

    mia::WorldObject *obj = new mia::WorldObject();
    obj->AddComponent(new mia::Portrait(
        mia::_SpriteHandler().MakeCut(mia::v2i(0, 0), mia::v2i(18, 16))
    ));

    while (true)
    {
        mia::_Game().Update();

        if (mia::_Input().isQuit()) break;
    }

    mia::_Game().ClearWindow();

    return 0;
}