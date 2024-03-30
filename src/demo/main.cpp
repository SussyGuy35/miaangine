#include "miaangine.hpp"
#include <string>

int main(int argc, char* argv[])
{
    mia::_Game().InitWindow();

    while (true)
    {
        mia::_Game().Step();

        if (mia::_Input().isQuit()) break;
    }

    mia::_Game().ClearWindow();

    return 0;
}