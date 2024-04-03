#include "miaangine.hpp"
#include <string>

int main(int argc, char* argv[])
{
    mia::_Game().InitWindow();

    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/Character.png");

    for (int i = 0 ; i < 1000; i++)
    {
        for (int j = 0 ; j < 1000; j++)
        {
            mia::Object *obj = new mia::Object(
                "A",
                j * 1, i * 1
            );
            mia::Portrait *prt = new mia::Portrait(
                mia::_SpriteHandler().MakeCut(mia::v2i(32 * 0, 32 * 3), mia::v2i(32, 32))
            );
            obj->AddComponent(prt);
        }
    }

    mia::_Camera().SetCenter(mia::v2f(0, 0));


    while (true)
    {
        mia::_Game().Update();

        if (mia::_Input().getKey(SDL_SCANCODE_D)) mia::_Camera().position().x += mia::_Camera().size() * .5 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_A)) mia::_Camera().position().x -= mia::_Camera().size() * .5 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_W)) mia::_Camera().position().y += mia::_Camera().size() * .5 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_S)) mia::_Camera().position().y -= mia::_Camera().size() * .5 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_E)) mia::_Camera().Resize(mia::_Camera().size() - 1 * mia::_Camera().size() * mia::_Time().deltaTime(), mia::v2f(.5, .5));
        if (mia::_Input().getKey(SDL_SCANCODE_Q)) mia::_Camera().Resize(mia::_Camera().size() + 1 * mia::_Camera().size() * mia::_Time().deltaTime(), mia::v2f(.5, .5));

        printf("%f\t%f\n", mia::_Time().fps(), mia::_Time().deltaTime());

        if (mia::_Input().isQuit()) break;

        mia::_Game().Render();
    }

    mia::_Game().ClearWindow();

    return 0;
}