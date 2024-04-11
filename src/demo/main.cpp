#include "miaangine.hpp"
#include <string>

#include "renderer.hpp"

int main(int argc, char* argv[])
{
    mia::_Game().InitWindow();

    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/SpriteTest.png");

    mia::_Renderer().SetRenderBodies(true);

    mia::Object *a = new mia::Object("A", 1, 2);
    mia::Object *b = new mia::Object("B", 3, 2);
    mia::Object *c = new mia::Object("C", 5, 2);
    mia::Body *bodyA = new mia::Body(a);
    mia::Body *bodyB = new mia::Body(b);
    mia::Body *bodyC = new mia::Body(c);
    mia::_Physics().RegisterBody(bodyA);
    mia::_Physics().RegisterBody(bodyB);
    mia::_Physics().RegisterBody(bodyC);

    while (true)
    {
        // mia::_Game().Update();

        bodyA->velocity().x = 3;
        bodyB->velocity().x = 1;
        bodyC->velocity().x = 1;

        mia::_Input().Update();
        if (mia::_Input().getKeyDown(SDL_SCANCODE_SPACE))
        {
            mia::_Game().Update();
        }

        if (mia::_Input().isQuit()) break;

        // mia::_Renderer().ClearDrawRects();
        mia::_Game().Render();
    }

    mia::_Game().ClearWindow();

    return 0;
}