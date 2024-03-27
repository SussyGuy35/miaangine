#include "miaangine.hpp"

#include <cstdlib>
#include <ctime>

#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif

using namespace mia;

int main(int argc, char *argv[])
{
    srand(std::time(0));

    generic().Init();

    Object *bird = new Object("Bird", 1, 1);
    bird->InitSprite(1, 1);
    // bird->sprite().Load("D:/SDL/miaangine/asset/flappy-bird/bird-00.png");
    bird->InitBody(1);
    bird->InitCollider(1, 1);

    Object *box = new Object("Box", 5, 3);
    box->InitSprite(1, 1);
    box->InitBody(1);
    box->InitCollider(1, 1);

    // TilemapLayout *tm = new TilemapLayout("D:/SDL/miaangine/asset/platformer/map01.txt");
    tilemap().AddTilemap(new TilemapLayout("D:/SDL/miaangine/asset/platformer/map-layout.txt"), new TilemapPalette("D:/SDL/miaangine/asset/platformer/map-palette.txt"));
    tilemap().Load(0);

    while (true)
    {
        generic().NewFrame();

        bird->body().velocity() = Vector2<>::zero();
        if (input().GetButton("Up")) bird->body().velocity().y = 3;
        if (input().GetButton("Down")) bird->body().velocity().y = -3;
        if (input().GetButton("Left")) bird->body().velocity().x = -3;
        if (input().GetButton("Right")) bird->body().velocity().x = 3;

        if (bird->collider().isColliding()) bird->sprite().color() = {255, 0, 0, 255};
        else bird->sprite().color() = {255, 255, 255, 255};

        if (box->collider().isColliding()) box->sprite().color() = {0, 255, 0, 255};
        else box->sprite().color() = {255, 255, 255, 255};

        camera().position() -= Vector2<>(.001, .001);

        if (input().isQuit()) break;

        generic().Render();
    }

    generic().End();

    return 0;
}