#include "miaangine.hpp"

#include "box.hpp"
#include "player/player.hpp"

int main(int argc, char* argv[])
{
    std::srand(std::time(0));

    mia::_Game().InitWindow();

    std::vector<Box*> boxes;
    boxes.push_back( new Box(9, .8, 10, 1) );
    boxes.push_back( new Box(0, 0, 10, 1) );
    // boxes.push_back( new Box(2, 0, 5, 3) );

    mia::_Renderer().RenderBodiesCollision(true);

    Player *player = new Player(7, 1);
    mia::_Camera().SetCenter({5, 3});

    // mia::TilemapPalette *pl = new mia::TilemapPalette();
    // pl->AddSprite(mia::_SpriteHandler().MakeCut({0, 0}, {32, 32}));
    // pl->AddSprite(mia::_SpriteHandler().MakeCut({0, 0}, {32, 32}));
    // mia::Tilemap *tm = new mia::Tilemap("D:/SDL/miaangine/asset/map.txt", pl, {1, 1});
    // mia::_Renderer().RegisterTilemap(tm);
    // mia::_Physics().RegisterTilemap(tm);

    while (true)
    {
        if (mia::_Input().getKey(SDL_SCANCODE_W)) mia::_Camera().position().y += 10 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_A)) mia::_Camera().position().x -= 10 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_S)) mia::_Camera().position().y -= 10 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_D)) mia::_Camera().position().x += 10 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_Q)) mia::_Camera().Resize(mia::_Camera().size() * 1.001, mia::v2f(0.5, 0.5));
        if (mia::_Input().getKey(SDL_SCANCODE_E)) mia::_Camera().Resize(mia::_Camera().size() * 0.999, mia::v2f(0.5, 0.5));
        // FIXME

        mia::_Game().Update();

        // printf("%f %f\n", player->position().x, player->position().y);

        if (mia::_Input().isQuit()) break;

        mia::_Game().Render();

        SDL_Delay(5);
    }

    mia::_Game().ClearWindow();

    return 0;
}