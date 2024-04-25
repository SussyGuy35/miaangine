#include "miaangine.hpp"

#include "box.hpp"
#include "player/player.hpp"
#include "ui-main.hpp"
#include "level.hpp"
#include "obstacle/spring.hpp"
#include "particle.hpp"

int main(int argc, char* argv[])
{
    std::srand(std::time(0));

    mia::_Game().InitWindow();

    // mia::_Audio().Play(mia::_Audio().Insert("D:/SDL/miaangine/asset/ost.wav", -1));

    Player *mainPlayer = new Player(0.0, 0.0);

    Spring spr = Spring(mainPlayer, {10, 6});

    mia::TilemapPalette *mapPalette = new mia::TilemapPalette();
    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/tileset-16x16.png");
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({0 , 32}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({16, 32}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({32, 32}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({0 , 16}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({16, 16}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({32, 16}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({0 , 0 }, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({16, 0 }, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({32, 0 }, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({48, 0 }, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({64, 0 }, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({48, 16}, {16, 16}));
    mapPalette->AddSprite(mia::_SpriteHandler().MakeCut({64, 16}, {16, 16}));

    Level *level00 = new Level("D:/SDL/miaangine/asset/map.txt", mapPalette);
    level00->startPlayerPosition = {1, 5};
    level00->startCameraPosition = {0, 0};
    level00->startCameraSize = 20;
    level00->player = mainPlayer;
    level00->ActivateMap();
    // level00.ReloadLevel();

    while (true)
    {
        if (mia::_Input().getKey(SDL_SCANCODE_W)) mia::_Camera().position().y += 10 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_A)) mia::_Camera().position().x -= 10 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_S)) mia::_Camera().position().y -= 10 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_D)) mia::_Camera().position().x += 10 * mia::_Time().deltaTime();
        if (mia::_Input().getKey(SDL_SCANCODE_Q)) mia::_Camera().Resize(mia::_Camera().size() * 1.001, mia::v2f(0.5, 0.5));
        if (mia::_Input().getKey(SDL_SCANCODE_E)) mia::_Camera().Resize(mia::_Camera().size() * 0.999, mia::v2f(0.5, 0.5));
        // FIXME

        if (mia::_Input().getKeyDown(SDL_SCANCODE_R)) level00->ReloadLevel();

        mia::_Game().Update();

        // printf("%f %f\n", player->position().x, player->position().y);

        if (mia::_Input().isQuit()) break;

        mia::_Game().Render();

        // SDL_Delay(50);
    }

    mia::_Game().ClearWindow();

    return 0;
}