#include "miaangine.hpp"
#include <string>

#include "renderer.hpp"

int main(int argc, char* argv[])
{
    mia::_Game().InitWindow();

    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/SpriteTest.png");

    // const int num = 5;
    // mia::Object *obj[num][num];
    // mia::Portrait *prt[num][num];
    // mia::Body *bod[num][num];
    // for (int i = 0 ; i < num; i++)
    // {
    //     for (int j = 0; j < num; j++)
    //     {
    //         obj[i][j] = new mia::Object(
    //             i * 3, j * 3 + 5
    //         );

    //         prt[i][j] = new mia::Portrait(
    //             obj[i][j],
    //             mia::_SpriteHandler().MakeCut(mia::v2i(0, 0), mia::v2i(32, 32))
    //         );
    //         mia::_Renderer().RegisterPortrait(prt[i][j]);

    //         bod[i][j] = new mia::Body(
    //             obj[i][j],
    //             mia::_BODY_DYNAMIC,
    //             1, 1
    //         );
    //         mia::_Physics().RegisterBody(bod[i][j]);
    //     }
    // }

    // for (int i = 0 ; i < num; i++)
    // {
    //     bod[i][0]->AddForce({0, -1});
    // }
    
    // mia::Object *plane = new mia::Object(
    //     0, 0
    // );
    // mia::Body *planeBody = new mia::Body(
    //     plane,
    //     mia::_BODY_STATIC,
    //     100, 1
    // );

    mia::Object *obj[3];
    mia::Portrait *prt[3];
    mia::Body *bod[3];
    obj[0] = new mia::Object(1, 0);
    obj[1] = new mia::Object(5, 5);
    obj[2] = new mia::Object(4, 4);
    prt[0] = new mia::Portrait(obj[0], mia::_SpriteHandler().MakeCut(mia::v2i(0, 0), mia::v2i(32, 32)));
    prt[1] = new mia::Portrait(obj[1], mia::_SpriteHandler().MakeCut(mia::v2i(0, 0), mia::v2i(32, 32)));
    prt[2] = new mia::Portrait(obj[2], mia::_SpriteHandler().MakeCut(mia::v2i(0, 0), mia::v2i(32, 32)));
    bod[0] = new mia::Body(obj[0], mia::_BODY_DYNAMIC, {1, 1});
    bod[1] = new mia::Body(obj[1], mia::_BODY_STATIC, {1, 1});
    bod[2] = new mia::Body(obj[2], mia::_BODY_STATIC, {1, 1});

    mia::_Renderer().RegisterPortrait(prt[0]);
    mia::_Renderer().RegisterPortrait(prt[1]);
    mia::_Renderer().RegisterPortrait(prt[2]);
    mia::_Physics().RegisterBody(bod[0]);
    mia::_Physics().RegisterBody(bod[1]);
    mia::_Physics().RegisterBody(bod[2]);

    bod[1]->AddForce({0, -2});

    while (true)
    {
        mia::_Game().Update();

        if (mia::_Input().getKey(SDL_SCANCODE_D)) mia::_Camera().position().x += mia::_Camera().size() * .5 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_A)) mia::_Camera().position().x -= mia::_Camera().size() * .5 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_W)) mia::_Camera().position().y += mia::_Camera().size() * .5 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_S)) mia::_Camera().position().y -= mia::_Camera().size() * .5 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_E)) mia::_Camera().Resize(mia::_Camera().size() - 1 * mia::_Camera().size() * mia::_Time().deltaTime(), mia::v2f(.5, .5));
        if (mia::_Input().getKey(SDL_SCANCODE_Q)) mia::_Camera().Resize(mia::_Camera().size() + 1 * mia::_Camera().size() * mia::_Time().deltaTime(), mia::v2f(.5, .5));

        bod[0]->velocity() = mia::v2f::zero();
        if (mia::_Input().getKey(SDL_SCANCODE_RIGHT)) bod[0]->velocity().x = 6;
        if (mia::_Input().getKey(SDL_SCANCODE_LEFT)) bod[0]->velocity().x = -6;
        if (mia::_Input().getKey(SDL_SCANCODE_UP)) bod[0]->velocity().y = 6;
        if (mia::_Input().getKey(SDL_SCANCODE_DOWN)) bod[0]->velocity().y = -6;

        if (mia::_Input().isQuit()) break;

        mia::_Game().Render();
    }

    mia::_Game().ClearWindow();

    return 0;
}