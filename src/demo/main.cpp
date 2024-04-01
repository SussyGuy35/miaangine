#include "miaangine.hpp"
#include <string>

int main(int argc, char* argv[])
{
    mia::_Game().InitWindow();

    // mia::WorldObject *obj = new mia::WorldObject();
    // obj->AddComponent(new mia::Portrait());

    while (true)
    {
        mia::_Game().Update();

        if (mia::_Input().isQuit()) break;
    }

    mia::_Game().ClearWindow();

    return 0;
}