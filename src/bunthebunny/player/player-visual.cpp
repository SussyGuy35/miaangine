#include "player-visual.hpp"

PlayerVisual::PlayerVisual(Player *manager):
    _manager(manager)
{
    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/Character.png");
    _sprites.push_back( mia::_SpriteHandler().MakeCut({0, 0}, {32, 32}) );
}

PlayerVisual::~PlayerVisual()
{
    for (mia::Sprite* sprite : _sprites) delete sprite;
    _sprites.clear();
}

mia::Sprite* PlayerVisual::GetSprite(int index)
{
    return _sprites[index];
}