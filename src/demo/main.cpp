#include "miaangine.hpp"
#include <string>

int main(int argc, char* argv[])
{
    mia::_Game().InitWindow();

    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/SpriteTest.png");

    mia::Object *obj = new mia::Object();
    mia::Portrait *prt = new mia::Portrait(
        mia::_SpriteHandler().MakeCut(mia::v2i(0, 0), mia::v2i(32, 32))
    );
    obj->AddComponent(prt);
    mia::Body *bdy = new mia::Body(
        1, mia::v2f(0, 0)
    );
    obj->AddComponent(bdy);

    prt->pivot() = mia::v2f(0, 0);
    prt->offset() = mia::v2f(.5, 1);

    mia::_Camera().SetCenter(mia::v2f(0, 0));

    while (true)
    {
        mia::_Game().Update();

        if (mia::_Input().getKey(SDL_SCANCODE_D)) mia::_Camera().position().x += mia::_Camera().size() * .5 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_A)) mia::_Camera().position().x -= mia::_Camera().size() * .5 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_W)) mia::_Camera().position().y += mia::_Camera().size() * .5 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_S)) mia::_Camera().position().y -= mia::_Camera().size() * .5 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_E)) mia::_Camera().Resize(mia::_Camera().size() * 0.997, mia::v2f(.5, .5));
        if (mia::_Input().getKey(SDL_SCANCODE_Q)) mia::_Camera().Resize(mia::_Camera().size() * 1.003, mia::v2f(.5, .5));
        printf("%f %f - %f\n", mia::_Camera().position().x, mia::_Camera().position().y, mia::_Camera().size());

        if (mia::_Input().isQuit()) break;

        mia::_Game().Render();

        SDL_Delay(1);
    }

    mia::_Game().ClearWindow();

    return 0;
}