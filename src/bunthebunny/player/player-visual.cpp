#include "player-visual.hpp"

#include "player.hpp"
#include "player-movement.hpp"

PlayerVisual::PlayerVisual(Player *manager):
    _manager(*manager),
    _idleAnimation(mia::Clip()),
    _runAnimation(mia::Clip()),
    _currentClip(&_idleAnimation)
{
    _idleAnimation.MakeAnimation("D:/SDL/miaangine/asset/Character-48x48.png", {0, 0}, {48 * 8, 48}, {48, 48});
    _runAnimation.MakeAnimation("D:/SDL/miaangine/asset/Character-48x48.png", {0, 48}, {48 * 8, 48}, {48, 48});
    _jumpAnimation.MakeAnimation("D:/SDL/miaangine/asset/Character-48x48.png", {0, 48*2}, {48, 48}, {48, 48});
    _fallAnimation.MakeAnimation("D:/SDL/miaangine/asset/Character-48x48.png", {48*2, 96}, {48, 48}, {48, 48});
}

PlayerVisual::~PlayerVisual()
{
    _idleAnimation.DestroyAllSprite();
    _runAnimation.DestroyAllSprite();
}

Player& PlayerVisual::GetManager()
{
    return _manager;
}

mia::Sprite* PlayerVisual::GetSprite()
{
    return _currentClip->GetCurrentSprite();
}

void PlayerVisual::Update()
{
    PlayCurrentAnimation();

    switch (_manager.movement().GetState())
    {
    case PlayerMovementState::STANDING:
        _currentClip = &_idleAnimation;
        break;

    case PlayerMovementState::RUNNING:
        _currentClip = &_runAnimation;
        break;

    case PlayerMovementState::JUMPING:
        _currentClip = &_jumpAnimation;
        break;

    case PlayerMovementState::FALLING:
        _currentClip = &_fallAnimation;
        break;

    case PlayerMovementState::DASH_PREPARE:
    case PlayerMovementState::DASHING:
        mia::v2f dir = _manager.movement().GetDashDirection();
        float angle = std::tan(dir.y / dir.x);
        // TODO
        break;

    default:
        _currentClip = &_idleAnimation;
        break;
    }
}

void PlayerVisual::PlayCurrentAnimation()
{
    _frameTimer -= mia::_Time().deltaTime();

    if (_frameTimer <= 0)
    {
        _currentClip->NextSprite();
        _frameTimer = 0.1;
    }
}