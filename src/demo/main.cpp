#include "miaangine.hpp"
#include <string>

#include "renderer.hpp"

int main(int argc, char* argv[])
{
    mia::_Game().InitWindow();

    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/SpriteTest.png");

    mia::Object *obj[100][100];
    mia::Portrait *prt[100][100];
    mia::Body *bod[100][100];
    for (int i = 0 ; i < 100; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            obj[i][j] = new mia::Object(
                "A",
                i * 3, j * 3 + 2
            );

            prt[i][j] = new mia::Portrait(
                mia::_SpriteHandler().MakeCut(mia::v2i(0, 0), mia::v2i(32, 32))
            );
            obj[i][j]->AddComponent(prt[i][j]);

            bod[i][j] = new mia::Body(
                1, {1, -1}
            );
            obj[i][j]->AddComponent(bod[i][j]);
        }
    }

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

        // printf("%f\t%f\n", mia::_Time().fps(), mia::_Time().deltaTime());

        if (mia::_Input().isQuit()) break;

        mia::_Game().Render();
    }

    mia::_Game().ClearWindow();

    return 0;
}