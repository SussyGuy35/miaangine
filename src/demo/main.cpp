#include "miaangine.hpp"
#include <string>

#include "renderer.hpp"

int main(int argc, char* argv[])
{
    mia::_Game().InitWindow();

    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/SpriteTest.png");

    const int num = 10;
    mia::Object *obj[num][num];
    mia::Portrait *prt[num][num];
    mia::Body *bod[num][num];
    for (int i = 0 ; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            obj[i][j] = new mia::Object(
                i * 3, j * 3 + 5
            );

            prt[i][j] = new mia::Portrait(
                obj[i][j],
                mia::_SpriteHandler().MakeCut(mia::v2i(0, 0), mia::v2i(32, 32))
            );
            mia::_Renderer().RegisterPortrait(prt[i][j]);

            bod[i][j] = new mia::Body(
                obj[i][j],
                mia::_BODY_DYNAMIC,
                1, 1
            );
            mia::_Physics().RegisterBody(bod[i][j]);
        }
    }
    
    mia::Object *plane = new mia::Object(
        0, 0
    );
    mia::Body *planeBody = new mia::Body(
        plane,
        mia::_BODY_STATIC,
        100, 1
    );

    mia::_Camera().position() = (mia::v2f(0, 0));

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