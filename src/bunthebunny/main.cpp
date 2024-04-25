#include "miaangine.hpp"

#include "box.hpp"
#include "player/player.hpp"
#include "ui-main.hpp"
#include "level.hpp"
#include "obstacle/spring.hpp"
#include "obstacle/surfplate.hpp"
#include "particle.hpp"
#include "camera-controller.hpp"

int main(int argc, char* argv[])
{
    std::srand(std::time(0));

    mia::_Game().InitWindow();

    // mia::_Audio().Play(mia::_Audio().Insert("D:/SDL/miaangine/asset/ost.wav", -1));

    Player *mainPlayer = new Player(0.0, 0.0);

    Spring spr = Spring(mainPlayer, {10, 6});
    Surfplate sup = Surfplate(mainPlayer, {15, .925 *6});

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
    level00->startPlayerPosition = {0, 5};
    level00->startCameraPosition = {0, 0};
    level00->startCameraSize = 45;
    level00->player = mainPlayer;
    level00->ActivateMap();
    level00->ReloadLevel();

    CamaraController *camMan = new CamaraController(mainPlayer);
    camMan->leftBound = 0;
    camMan->rightBound = 200;
    camMan->idealPlayerOffset = 5;
    camMan->camFollowingBound = 7;

    while (true)
    {
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