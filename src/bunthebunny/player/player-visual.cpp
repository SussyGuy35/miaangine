#include "player-visual.hpp"

PlayerVisual::PlayerVisual(Player *manager):
    _manager(manager),
    _sprite(nullptr),
    _idleAnimation(mia::Clip()),
    _runAnimation(mia::Clip())
{
    _idleAnimation.MakeAnimation("D:/SDL/miaangine/asset/Character-48x48.png", {0, 0}, {48, 48}, {48, 48});
    _runAnimation.MakeAnimation("D:/SDL/miaangine/asset/Character-48x48.png", {0, 48}, {48 * 8, 48}, {48, 48});

    _sprite = _runAnimation.GetCurrentSprite();
}

PlayerVisual::~PlayerVisual()
{
    _idleAnimation.DestroyAllSprite();
    _runAnimation.DestroyAllSprite();
}

mia::Sprite* PlayerVisual::GetSprite()
{
    return _sprite;
}

void PlayerVisual::Update()
{
    // FIXME
    count -= mia::_Time().deltaTime();
    printf("%f\n", count);

    if (count <= 0)
    {
        _sprite = _runAnimation.NextSprite();
        count = 0.2;
    }
}