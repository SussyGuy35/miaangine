#include "miaangine.hpp"
#include <string>

int main(int argc, char* argv[])
{
    mia::_Game().InitWindow();

    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/SpriteTest.png");

    mia::WorldObject *obj = new mia::WorldObject();
    obj->AddComponent(new mia::Portrait(
        mia::_SpriteHandler().MakeCut(mia::v2i(0, 0), mia::v2i(16, 16))
    ));

    mia::_Camera().SetCenter(mia::v2f(0, 0));

    SDL_Log("%f %f\n", mia::_Camera().getCameraWidth(), mia::_Camera().getCameraHeight());
    SDL_Log("%f %f\n", mia::_Camera().position().x, mia::_Camera().position().y);


    while (true)
    {
        mia::_Game().Update();

        if (mia::_Input().getKeyDown(SDL_SCANCODE_D)) mia::_Camera().position().x += 1;
        if (mia::_Input().getKeyDown(SDL_SCANCODE_A)) mia::_Camera().position().x -= 1;
        if (mia::_Input().getKeyDown(SDL_SCANCODE_W)) mia::_Camera().position().y += 1;
        if (mia::_Input().getKeyDown(SDL_SCANCODE_S)) mia::_Camera().position().y -= 1;

        if (mia::_Input().isQuit()) break;
    }

    mia::_Game().ClearWindow();

    return 0;
}